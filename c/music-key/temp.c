#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/raylib-6.0/include/raylib.h"

#include "instrument.c"

#define return_defer(value) do { result = (value); goto defer; } while(0)
#define ARRAY_LEN(s) (sizeof(s)/sizeof(s[0]))

#define INIT_CAPACITY 16

#define DA_NEW(Type, Name)                                                \
    typedef struct {                                                      \
        Type  *items;                                                     \
        size_t count;                                                     \
        size_t capacity;                                                  \
    } Name;                                                               \
    static inline Name *Name##_new(void) {                                \
        Name *da = malloc(sizeof(*da));                                   \
        assert(da != NULL);                                               \
        da->capacity = INIT_CAPACITY;                                     \
        da->items = malloc(INIT_CAPACITY * sizeof(*da->items));           \
        assert(da->items != NULL);                                        \
        da->count = 0;                                                    \
        return da;                                                        \
    }                                                                     \
    static inline void Name##_add(Name *da, Type item) {                  \
        if (da->count >= da->capacity) {                                  \
            da->capacity = da->capacity == 0 ? 16 : da->capacity * 2;     \
            da->items = realloc(da->items, da->capacity * sizeof(Type));  \
            assert((da)->items != NULL && "Ran out of memory");           \
        }                                                                 \
        da->items[da->count++] = item;                                    \
    }                                                                     \
    static inline void Name##_free(Name *da) { free(da->items); free(da); }

#define SCREEN_FACTOR    200
#define SCREEN_WIDTH     (4*SCREEN_FACTOR)
#define SCREEN_HEIGHT    (4*SCREEN_FACTOR)
#define NOTE_RADIUS      (0.015*SCREEN_HEIGHT)
#define NOTE_OPEN_COLOR  ColorFromHSV(120, 1, 1)
#define NOTE_CLOSE_COLOR ColorFromHSV(30, 1, 1)

#define BUFFER_SIZE      (1024*2)
#define SAMPLERATE       44100
#define SAMPLESIZE       32
#define CHANNELS         1
#define ROOT_NOTE        440.0f
#define TWO_PI           6.28318530717958647692
#define BPM              120.0f
#define BEAT_SECS        (60.0f/BPM)
#define BAR_BEATS        4
#define BAR_SECS         (BAR_BEATS*BEAT_SECS)
#define BAR_QUANT        32
#define QUANT_SECS       (BAR_SECS/BAR_QUANT)

#define NEXT_SEMITONE    powf(2.0f, 1.0f/12.0f)

#define ATTACK_FRAME     (2205)
#define RELEASE_FRAME    (4410)

const KeyboardKey KEY_MAP[] = {
    KEY_Z, KEY_S, KEY_X, KEY_D, KEY_C, KEY_F, KEY_V, KEY_G, KEY_B, KEY_H,
    KEY_N, KEY_J, KEY_M, KEY_K, KEY_COMMA
};
#define NOTE_COUNT       ARRAY_LEN(KEY_MAP)

float clamp_f(float f, float min_val, float max_val) {
    if (f < min_val) return min_val;
    if (f > max_val) return max_val;
    return f;
}

float min_f(float val, float max_val) {
    return (val < max_val) ? val : max_val;
}

typedef struct {
    int          timestamp;
    bool         start;
    int          key_idx;
    int          semitone;
    instrument_t instrument;
} event_t;

DA_NEW(event_t, event_da);

typedef struct {
    int          semitone;
    bool         playing;
    size_t       start_frame;
    instrument_t instrument;
} note_t;

event_t *peek(event_da *es) {
    if (es == NULL || es->count == 0) return NULL;
    return &es->items[es->count - 1];
}

note_t notes_replay[NOTE_COUNT];
note_t notes_monitor[NOTE_COUNT];

size_t frame_count = 0;

float semitone_to_freq(float semitone) {
    return ROOT_NOTE * powf(NEXT_SEMITONE, semitone);
}

float note_update(note_t *note) {
    float age = (float)(frame_count - note->start_frame);
    float volumn = clamp_f(age / ATTACK_FRAME, 0.0f, 1.0f);
    float time = (float)(frame_count) / SAMPLERATE;
    float frequency = semitone_to_freq((float)note->semitone);
    return instrument_run(note->instrument, time * frequency) * volumn;
}

typedef struct {
    size_t       stop_frame;
    float        stop_at_volumn;
    float        semitone;
    instrument_t instrument;
} note_release_t;

DA_NEW(note_release_t, note_release_da);

float note_release_update(note_release_t *note_rel) {
    float age = (float)(frame_count - note_rel->stop_frame);
    float prog = clamp_f(age / RELEASE_FRAME, 0.0f, 1.0f);
    float volumn = 0.5f * (1.0f + cosf(PI * prog)) * note_rel->stop_at_volumn;
    float time = (float)(frame_count) / SAMPLERATE;
    float frequency = semitone_to_freq(note_rel->semitone);
    return instrument_run(note_rel->instrument, time * frequency) * volumn;
}

void note_releases_unordered_rm_by_idx(note_release_da *nrs, size_t idx) {
    assert(idx < nrs->count);
    note_release_t *array = nrs->items;
    size_t last_idx = nrs->count - 1;
    if (idx != last_idx) array[idx] = array[last_idx];
    nrs->count -= 1;
}

void note_press(note_t *note, int semitone, instrument_t instrument) {
    if (!note->playing) {
        note->playing     = true;
        note->start_frame = frame_count;
        note->semitone    = semitone;
        note->instrument  = instrument;
    }
}

note_release_da *g_note_releases = NULL;

void note_released(note_t *note) {
    if (note->playing) {
        note->playing = false;
        float age = (float)(frame_count - note->start_frame);
        float volumn = clamp_f(age / ATTACK_FRAME, 0.0f, 1.0f);
        note_release_da_add(g_note_releases, (note_release_t) {
            .stop_frame     = frame_count,
            .stop_at_volumn = volumn,
            .semitone       = (float)note->semitone,
            .instrument     = note->instrument,
        });
    }
}

bool note_released_done(note_release_t *nr) {
    return (frame_count - nr->stop_frame) >= RELEASE_FRAME;
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

    event_da *events = event_da_new();
    g_note_releases = note_release_da_new();

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    float beat_time = 0.0f;
    int record_bar_amount = 0;
    int quant_for_play = 0;
    int quant_for_play_prev = -1;
    instrument_t instrument_current = instrument_sine();

    while (!WindowShouldClose()) {
        float beat_time_prev = beat_time;
        beat_time += GetFrameTime();
        int quant = (int)(beat_time / QUANT_SECS);

        if (fmodf(beat_time_prev, BEAT_SECS) > fmodf(beat_time, BEAT_SECS)) {
            // PlaySound(music);
        }

        switch (state) {
        case REPLAY:
            if (events->count > 0 && record_bar_amount > 0) {
                event_t *last_event = peek(events);
                record_bar_amount = (last_event->timestamp + BAR_QUANT - 1) / BAR_QUANT;
                if (record_bar_amount < 1) record_bar_amount = 1;
                quant_for_play = quant % (record_bar_amount * BAR_QUANT);

                if (quant_for_play != quant_for_play_prev) {
                    for (size_t i = 0; i < events->count; ++i) {
                        if (events->items[i].timestamp == quant_for_play) {
                            int k = events->items[i].key_idx;
                            if (events->items[i].start) {
                                note_press(&notes_replay[k], events->items[i].semitone, instrument_current);
                            } else {
                                note_released(&notes_replay[k]);
                            }
                        }
                    }
                    quant_for_play_prev = quant_for_play;
                }
            }
            break;

        case WAIT_FOR_EOB:
            if (fmodf(beat_time_prev, BAR_SECS) > fmodf(beat_time, BAR_SECS)) {
                state = RECORD;
                quant = 0;
                beat_time = 0.0f;
                quant_for_play_prev = -1;
                for (size_t i = 0; i < ARRAY_LEN(notes_monitor); ++i) {
                    if (notes_monitor[i].playing) {
                        event_da_add(events, (event_t) {
                            .timestamp  = 0,
                            .start      = true,
                            .key_idx    = (int)i,
                            .semitone   = notes_monitor[i].semitone,
                            .instrument = notes_monitor[i].instrument,
                        });
                    }
                }
            }
            break;

        case RECORD:
            break;
        }

        if (IsKeyPressed(KEY_SPACE)) {
            switch (state) {
            case REPLAY:
                state = WAIT_FOR_EOB;
                events->count = 0;
                for (size_t i = 0; i < NOTE_COUNT; ++i) {
                    note_released(&notes_replay[i]);
                }
                break;
            case RECORD:
                record_bar_amount = (quant + BAR_QUANT - 1) / BAR_QUANT;
                if (record_bar_amount < 1) record_bar_amount = 1;
                beat_time = 0.0f;
                quant_for_play_prev = -1;
                state = REPLAY;
                break;
            case WAIT_FOR_EOB:
                state = REPLAY;
                break;
            }
        }

        int shift = IsKeyDown(KEY_BACKSPACE) ? -12 : 0;
        for (int key = 0; key < (int)NOTE_COUNT; ++key) {
            if (IsKeyDown(KEY_MAP[key]) && !notes_monitor[key].playing) {
                int pitch = key + shift;
                note_press(&notes_monitor[key], pitch, instrument_current);
                if (state == RECORD) {
                    event_da_add(events, (event_t) {
                        .timestamp  = quant,
                        .start      = true,
                        .key_idx    = key,
                        .semitone   = pitch,
                        .instrument = instrument_current,
                    });
                }
            } else if (!IsKeyDown(KEY_MAP[key]) && notes_monitor[key].playing) {
                if (state == RECORD) {
                    event_da_add(events, (event_t) {
                        .timestamp  = quant,
                        .start      = false,
                        .key_idx    = key,
                        .semitone   = notes_monitor[key].semitone,
                        .instrument = instrument_current,
                    });
                }
                note_released(&notes_monitor[key]);
            }
        }

        if (IsAudioStreamProcessed(synth)) {
            memset(buffer, 0, sizeof(buffer));
            for (size_t i = 0; i < BUFFER_SIZE; ++i) {
                float sample = 0.0f;
                int note_playing = 0;

                for (size_t key = 0; key < NOTE_COUNT; ++key) {
                    if (notes_monitor[key].playing) note_playing += 1;
                    if (notes_replay[key].playing)  note_playing += 1;
                }
                note_playing += (int)g_note_releases->count;

                if (note_playing > 0) {
                    float amp = 1.0f / (float)note_playing;
                    for (size_t semitone = 0; semitone < NOTE_COUNT; ++semitone) {
                        if (notes_monitor[semitone].playing) {
                            sample += note_update(&notes_monitor[semitone]) * amp;
                        }
                        if (notes_replay[semitone].playing) {
                            sample += note_update(&notes_replay[semitone]) * amp;
                        }
                    }
                    for (size_t r = 0; r < g_note_releases->count; ++r) {
                        sample += note_release_update(&g_note_releases->items[r]) * amp;
                    }
                }

                buffer[i] = clamp_f(sample, -1.0f, 1.0f);
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
        Vector2 state_indicator_pos = {(float)GetScreenWidth() - 50.0f, 50.0f};
        float radius = 20.0f;

        switch (state) {
        case REPLAY:
            DrawRing(state_indicator_pos, radius * 0.9f, radius, 0, 360, 100, YELLOW);
            break;
        case WAIT_FOR_EOB:
            DrawCircleV(state_indicator_pos, radius, BLUE);
            break;
        case RECORD:
            DrawCircleV(state_indicator_pos, radius, RED);
            break;
        }

        int active_bars = (record_bar_amount < 1) ? 1 : record_bar_amount;
        float quant_len = (float)GetScreenWidth() / (float)(BAR_QUANT * active_bars);
        float semitone_height = (float)GetScreenHeight() / (float)NOTE_COUNT;

        for (size_t i = 0; i < events->count; ++i) {
            Vector2 note_pos = {
                events->items[i].timestamp * quant_len,
                events->items[i].key_idx * semitone_height + (semitone_height / 2.0f)
            };
            Color color = events->items[i].start ? RED : BLUE;
            DrawCircleV(note_pos, 6, color);
        }

        int total_beat = BAR_BEATS * active_bars;
        float beat_len = (float)GetScreenWidth() / (float)total_beat;
        for (int i = 1; i < total_beat; ++i) {
            DrawLineV((Vector2){beat_len * i, 0},
                      (Vector2){beat_len * i, (float)GetScreenHeight()},
                      GRAY);
        }

        float total_loop_sec = BAR_SECS * (float)active_bars;
        float ph = (fmodf(beat_time, total_loop_sec) / total_loop_sec) * (float)GetScreenWidth();
        DrawLineV((Vector2){ph, 0},
                  (Vector2){ph, (float)GetScreenHeight()},
                  WHITE);

        EndDrawing();
    }

    note_release_da_free(g_note_releases);
    event_da_free(events);
    UnloadSound(music);
    UnloadAudioStream(synth);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
