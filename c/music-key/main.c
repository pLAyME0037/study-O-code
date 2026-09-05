#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/raylib-6.0/include/raylib.h"

#define return_defer(value) do { result = (value); goto defer; } while(0)
#define ARRAY_LEN(s) (sizeof(s)/sizeof(s[0]))

#define DA_NEW(Type, Name)                                               \
    typedef struct {                                                     \
        Type *items;                                                     \
        size_t count;                                                    \
        size_t capacity;                                                 \
    } Name;                                                              \
    static inline void Name##_add(Name *da, Type item) {                 \
        if (da->count >= da->capacity) {                                 \
            da->capacity = da->capacity == 0 ? 16 : da->capacity * 2;    \
            da->items = realloc(da->items, da->capacity * sizeof(Type)); \
            assert((da)->items != NULL && "Run out of memory");          \
        }                                                                \
        da->items[da->count++] = item;                                   \
    }                                                                    \
    static inline void Name##_free(Name *da) { free(da->items); }

#define BUFFER_SIZE 1024
#define SAMPLERATE  44100
#define SAMPLESIZE  32
#define CHANNELS    1
#define ROOT_NOTE   440.0
#define TWO_PI      (2.0f * PI)

#define BPM         120.0
#define BEAT_SECS   (60.0/BPM)
#define BAR_BEATS   4
#define BAR_SECS    (BAR_BEATS*BEAT_SECS)
#define BAR_QUANT   32
#define QUANT_SECS  (BAR_SECS/BAR_QUANT)

const KeyboardKey KEY_MAP[] = {
    KEY_Z, KEY_S, KEY_X, KEY_D, KEY_C, KEY_F, KEY_V, KEY_G, KEY_B, KEY_H,
    KEY_N, KEY_J, KEY_M, KEY_K, KEY_COMMA
};
#define NEXT_SEMITONE powf(2.0, 1.0/12.0)
#define INIT_CAPACITY 16
#define NOTE_COUNT    ARRAY_LEN(KEY_MAP)

float clamp_f(float f, float min, float max) {
    if (f < min) return min;
    if (f > max) return max;
    return f;
}

float min(float val, float max) {
    if (val < max) return val;
    if (val > max) return max;
    return max;
}

typedef struct {
    int  timestamp;
    bool start;
    int  semitone;
} Event;

DA_NEW(Event, Events);

// typedef struct {
//     Event *items;
//     size_t count;
//     size_t capacity;
// } Events;

typedef struct {
    bool playing;
    int  frame_stamp;
} Note;

Event *peek(Events *es) {
    if (es == NULL || es->count == 0) return NULL;
    return &es->items[es->count - 1];
}

Events *events_new(void) {
    Events *es = malloc(sizeof(*es));

    es->capacity = INIT_CAPACITY;
    es->items = malloc(INIT_CAPACITY * sizeof(*es->items));
    es->count = 0;

    return es;
}

void notes_add(Events *es, Event item) {
    if (es->capacity == es->count) {
        es->capacity *= 2;
        es->items = realloc(es->items, es->capacity * sizeof(*es->items));
    }
    es->items[es->count++] = item;
}

static void events_free(Events *el) {
    if (!el) return;
    free(el->items);
    free(el);
}

#define ATTACK_FRAME  (1000)
#define RELEASE_FRAME (1000)

Note notes_replay[NOTE_COUNT];
Note notes_monitor[NOTE_COUNT];

float semitone_to_freq(float semitone) {
    return ROOT_NOTE*powf(NEXT_SEMITONE, semitone);
}

float note_update(Note *note, int frame_count, float frequency) {
    float volumn = min((float)(frame_count - note->frame_stamp)/ATTACK_FRAME, 1.0);
    float time = (float)(frame_count)/SAMPLERATE;
    return sinf(TWO_PI*time*frequency)*volumn;
}

typedef struct {
    int   frame_stamp;
    float frequency;
    float volumn;
} NoteRelease;

DA_NEW(NoteRelease, NoteReleases);

// typedef struct {
//     NoteRelease *items;
//     size_t       count;
//     size_t       capacity;
// } NoteReleases;

// NoteReleases notes_release[NOTE_COUNT];

NoteReleases *notes_releases_new(void) {
    NoteReleases *nrs = malloc(sizeof(*nrs));

    nrs->capacity = INIT_CAPACITY;
    nrs->items = malloc(INIT_CAPACITY * sizeof(*nrs->items));
    nrs->count = 0;

    return nrs;
}

static void notes_releases_add(NoteReleases *nrs, NoteRelease item) {
    if (nrs->capacity == nrs->count) {
        // nrs->capacity *= 2;
        nrs->capacity = nrs->capacity == 0 ? INIT_CAPACITY : nrs->capacity * 2;
        nrs->items = realloc(nrs->items, nrs->capacity * sizeof(*nrs->items));
    }
    nrs->items[nrs->count++] = item;
}

float note_release_update(NoteRelease *note_rel, int frame_count) {
    float volumn = (1 - min((float)(frame_count - note_rel->frame_stamp)/RELEASE_FRAME, 1.0))*note_rel->volumn;
    float time = (float)(frame_count)/SAMPLERATE;
    return sinf(TWO_PI*time*note_rel->frequency)*volumn;
}

void note_releases_unordered_rm_by_idx(NoteReleases *nrs, size_t idx) {
    // assert(idx >= 0);
    assert(idx < nrs->count);

    NoteRelease *array = nrs->items;
    size_t last_idx = nrs->count - 1;
    if (idx != last_idx) array[idx] = array[last_idx];

    nrs->count -= 1;
}

static void notes_releases_free(NoteReleases *nrs) {
    if (!nrs) return;
    free(nrs->items);
    free(nrs);
}

void note_press(Note *note, int frame_count) {
    note->frame_stamp = frame_count;
    note->playing     = true;
}

NoteReleases *g_note_releases = NULL;
void note_released(Note *note, float frequency, int frame_count) {
    float volumn;
    if (note->playing) {
        note->playing = false;
        volumn = min((float)(frame_count - note->frame_stamp)/ATTACK_FRAME, 1.0);
        notes_releases_add(g_note_releases, (NoteRelease) {
            .frame_stamp = frame_count,
            .frequency   = frequency,
            .volumn      = volumn,
        });
    }
}

size_t frame_count = 0;
bool note_released_done(NoteRelease *nr) {
    return (float)(frame_count - nr->frame_stamp) >= RELEASE_FRAME;
}

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT);
    InitWindow(800, 600, "Music Key");
    InitAudioDevice();

    float buffer[BUFFER_SIZE];
    SetAudioStreamBufferSizeDefault(BUFFER_SIZE);
    AudioStream synth = LoadAudioStream(SAMPLERATE, SAMPLESIZE, CHANNELS);
    PlayAudioStream(synth);

    Sound music = LoadSound("./h-beats-clock-beat-effect-402705.mp3");

    enum { REPLAY, WAIT_FOR_EOB, RECORD } state = REPLAY;

    Events *events = events_new();
    g_note_releases = notes_releases_new();

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    float beat_time = 0.0f;
    int record_bar_amount = 0;
    int quant_for_play = 0;

    while (!WindowShouldClose()) {
        float beat_time_prev = beat_time;
        beat_time += GetFrameTime();
        int quant = beat_time/QUANT_SECS;

        if (fmodf(beat_time_prev, BEAT_SECS) > fmodf(beat_time, BEAT_SECS)) {
            // PlaySound(music);
            // UpdateMusicStream(music);
        }
        switch (state) {
        case REPLAY:
            if (events->count > 0 && record_bar_amount > 0) {
                Event *last_event = peek(events);
                record_bar_amount = (last_event->timestamp + BAR_QUANT - 1)/BAR_QUANT;
                if (record_bar_amount < 1) record_bar_amount = 1;
                quant_for_play = quant%(record_bar_amount*BAR_QUANT);
                for (size_t i = 0; i < events->count; ++i) {
                    if (events->items[i].timestamp == quant_for_play) {
                        if (events->items[i].start) {
                            note_press(&notes_replay[events->items[i].semitone], frame_count);
                        } else {
                            float freq = semitone_to_freq(events->items[i].semitone);
                            note_released(&notes_replay[events->items[i].semitone], freq, frame_count);
                        }
                    }
                }
            }
        break;
        case WAIT_FOR_EOB:
            if (fmodf(beat_time_prev, BAR_SECS) > fmodf(beat_time, BAR_SECS)) {
                state = RECORD;
                quant = 0;
                beat_time = 0.0;
                for (size_t i = 0; i < ARRAY_LEN(notes_monitor); ++i) {
                    if (notes_monitor[i].playing) {
                        notes_add(events, (Event) {
                            .timestamp = 0,
                            .start = true,
                            .semitone = (int)i,
                        });
                    }
                }
            }
        break;
        case RECORD:;
        }

        if (IsKeyPressed(KEY_SPACE)) {
            switch (state) {
            case REPLAY:
                state = WAIT_FOR_EOB;
                events->count = 0;
                for (size_t i = 0; i < NOTE_COUNT; ++i) {
                    note_released(&notes_replay[i], semitone_to_freq((float)i), frame_count);
                }
            break;
            case RECORD:
                // for (size_t i = 0; i < events->count; ++i) {
                //     Event e = events->items[i];
                //     printf("[ %d, %d, %d ]\n", e.timestamp.timestamp, e.start, e.semitone);
                // }
                record_bar_amount = (quant + BAR_QUANT - 1)/BAR_QUANT;
                if (record_bar_amount < 1) record_bar_amount = 1;
                beat_time = 0.0;
                state = REPLAY;
            break;
            case WAIT_FOR_EOB:
                state = REPLAY;
            break;
            }
        }

        int note_playing = 0;
        for (size_t key = 0; key < NOTE_COUNT; ++key) {
            if (IsKeyDown(KEY_MAP[key]) && !notes_monitor[key].playing) {
                note_press(&notes_monitor[key], frame_count);
                if (state == RECORD) {
                    notes_add(events, (Event) {
                        .timestamp = quant,
                        .start = true,
                        .semitone = (int)key,
                    });
                }
            } else if (!IsKeyDown(KEY_MAP[key]) && notes_monitor[key].playing) {
                float freq = semitone_to_freq((float)key);
                note_released(&notes_monitor[key], freq, frame_count);
                if (state == RECORD) {
                    notes_add(events, (Event) {
                        .timestamp = quant,
                        .start = false,
                        .semitone = (int)key,
                    });
                }
            }
            // if (notes_monitor[key]) note_playing += 1;
        }

        if (IsAudioStreamProcessed(synth)) {
            memset(buffer, 0, sizeof(buffer));
            for (size_t i = 0; i < BUFFER_SIZE; ++i) {
                float sample = 0.0f;
                note_playing = 0;
                for (size_t key = 0; key < NOTE_COUNT; ++key) {
                    if (notes_monitor[key].playing) note_playing += 1;
                    if (notes_replay[key].playing)  note_playing += 1;
                }
                note_playing += (int)g_note_releases->count;
                if (note_playing > 0) {
                    float amp = 1.0/note_playing;
                    for (size_t semitone = 0; semitone < NOTE_COUNT; ++semitone) {
                        float freq = semitone_to_freq((float)semitone);
                        if (notes_monitor[semitone].playing) {
                            sample += note_update(&notes_monitor[semitone], frame_count, freq)*amp;
                        }
                        if (notes_replay[semitone].playing) {
                            sample += note_update(&notes_replay[semitone], frame_count, freq)*amp;
                        }
                    }
                    for (size_t semitone = 0; semitone < g_note_releases->count; ++semitone) {
                        sample += note_release_update(&g_note_releases->items[semitone], frame_count)*amp;
                    }
                }
                buffer[i] = clamp_f(sample, -1., 1.);
                frame_count += 1;
            }
            for (size_t key = g_note_releases->count; key > 0; --key) {
                size_t idx = key - 1;
                if (note_released_done(&g_note_releases->items[idx])) {
                    note_releases_unordered_rm_by_idx(g_note_releases, idx);
                }
            }
            UpdateAudioStream(synth, buffer, ARRAY_LEN(buffer));
        }
        BeginDrawing();
        ClearBackground(GetColor(0x121218FF));
        Vector2 note_pos = {GetScreenWidth() - 50, 50};
        int radius = 20;
        switch (state) {
        case REPLAY: {
            DrawRing(note_pos, radius*0.9, radius, 0, 360, 100, YELLOW);
        } break;
        case WAIT_FOR_EOB: {
            DrawCircleV(note_pos, radius, BLUE);
        } break;
        case RECORD: {
            DrawCircleV(note_pos, radius, RED);
        } break;
        }

        record_bar_amount = 1;
        if (events->count > 0) {
            Event *last_event = peek(events);
            record_bar_amount = (last_event->timestamp + BAR_QUANT - 1)/BAR_QUANT;
            if (record_bar_amount < 1) record_bar_amount = 1;
        }

        float quant_len = (float)GetScreenWidth()/(BAR_QUANT*record_bar_amount);
        float semitone_height = (float)GetScreenHeight()/(float)NOTE_COUNT;
        for (size_t i = 0; i < events->count; ++i) {
            Vector2 note_pos = {
                events->items[i].timestamp*quant_len,
                events->items[i].semitone*semitone_height + (semitone_height/2.0)
            };
            Color color = events->items[i].start ? RED : BLUE;
            DrawCircleV(note_pos, 6, color);
        }

        int total_beat = BAR_BEATS*record_bar_amount;
        float beat_len = (float)GetScreenWidth()/total_beat;
        for (int i = 1; i < total_beat; ++i) {
            DrawLineV((Vector2){beat_len*i, 0},
                      (Vector2){beat_len*i, GetScreenHeight()},
                      GRAY);
        }
        float total_loop_sec = BAR_SECS*record_bar_amount;
        float ph = (fmodf(beat_time, total_loop_sec)/total_loop_sec)*GetScreenWidth();
        DrawLineV((Vector2){ph, 0},
                  (Vector2){ph, GetScreenHeight()},
                  WHITE);

        EndDrawing();
    }

    notes_releases_free(g_note_releases);
    events_free(events);
    UnloadSound(music);
    UnloadAudioStream(synth);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
