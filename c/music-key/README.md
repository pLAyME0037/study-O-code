# README.md

Audio synthesizer, keyboard monitor, and quantized loop recorder built with C and Raylib.

---

## 1. Macro Purpose

| Macro | Purpose |
|---|---|
|┌ `LERPF(a, b, t)` |┌ Linear interpolation: `(1 - t)*a + t*b`. |
|└ `.`            |└ Used in saw wave shaping.|
|┌ `TWO_PI` |┌ 2pi constant (`6.283185...`). Converts frequency |
|└ `.`    |└ $\times$ time to full sine wave radian phase. |
| `ARRAY_LEN(s)` | Element count of static array (`sizeof(s)/sizeof(s[0])`). |
|┌ `DA_NEW(Type, Name)` |┌ Generic dynamic array generator. Emits struct definition |
|└ `.`                |└ and `_new`, `_add`, `_free` functions for target type. |
| `INIT_CAPACITY` | Initial memory allocation slot count (16 items) for dynamic arrays. |
|┌` SCREEN_FACTOR`,   | ┌ |
|│ `SCREEN_WIDTH`,  | │ Visual display dimensions. |
|└ `SCREEN_HEIGHT` | └ |
|┌ `NOTE_RADIUS`,     |┌  |
|│ `NOTE_OPEN_COLOR`, |│ UI styling constants for sequencer visualization. |
|└ `NOTE_CLOSE_COLOR` |└  |
| `BUFFER_SIZE` | Audio chunk size (2048 frames) sent to sound card. |
|┌ `SAMPLERATE`, |┌  |
|│ `SAMPLESIZE`, |│ Audio device config (44100 Hz, 32-bit float, mono). |
|└ `CHANNELS`    |└  |
| `ROOT_NOTE` | Base pitch frequency (440.0 Hz = A4). |
|┌ `NEXT_SEMITONE` |┌ Equal temperament ratio $2^{1/12}$ (`powf(2.0, 1.0/12.0)`).  |
|└ `.`           |└ Multiplies frequency by semitone offset. |
|┌ `BPM`,      |┌ Tempo definition (120 BPM = 0.5s per beat). |
|└ `BEAT_SECS` |└  |
| `BAR_BEATS`, `BAR_SECS` | Measure length (4 beats = 2.0s per bar). |
| `BAR_QUANT`, `QUANT_SECS` | Time subdivision (32 ticks per bar = 0.0625s per tick). |
|┌ `ATTACK_FRAME`, |Envelope durations in audio samples  |
|└ `RELEASE_FRAME` |(Attack = 2205 frames / ~50ms, Release = 4410 frames / ~100ms).|
| `KEY_MAP`, `NOTE_COUNT` | Keyboard binding map array and total key count (15 notes). |
| `return_defer(value)` | Jump-to-defer macro for structured exits. |

---

## 2. Structures & Lifecycle

### `instrument_t`
Polymorphic waveform generator container.
- **Fields:** 
  - `func` (function pointer to wave formula),
  - `data` (`void*` state payload for duty cycle / inflection point).
- **Lifecycle:** Created via factory functions (`instrument_saw_tooth()`, etc.).
  Persists inside active notes and events.

### `event_t`
Sequencer note trigger record.
- **Fields:** 
  - `timestamp`  (quant tick index),
  - `start`      (`true` = press, `false` = release),
  - `key_idx`    (0–14 index),
  - `semitone`   (pitch offset),
  - `instrument` (wave type).
- **Lifecycle:** Allocated inside `event_da` during `RECORD` or `WAIT_FOR_EOB`. Read
  continuously during `REPLAY`. Freed on reset or program shutdown.

### `event_da`
Dynamic array for `event_t`.
- **Fields:** `items` heap pointer, `count`, `capacity`.
- **Lifecycle:** Created on `main()` startup via `event_da_new()`. Cleared (`count = 0`)
  when user begins new recording. Destroyed via `event_da_free()` at exit.

### `note_t`
Voice state for active continuous oscillator.
- **Fields:** 
  - `semitone`    (pitch offset),
  - `playing`     (`bool` active flag),
  - `start_frame` (sample timestamp when pressed),
  - `instrument`.
- **Lifecycle:** Statically allocated in fixed arrays `notes_monitor` and `notes_replay`.
State changes:
  - Idle (`playing = false`) to `note_press()` to Playing (`playing = true`, records `start_frame`).
  - Playing to `note_released()` to Idle (`playing = false`).

### `note_release_t`
Voice state for decaying note in release stage.
- **Fields:** 
  - `stop_frame` (sample timestamp when key released),
  - `stop_at_volumn` (gain level at release moment),
  - `semitone`,
  - `instrument`.
- **Lifecycle:** Created dynamically by `note_released()`, added to `g_note_releases`.
  Updated each audio frame until age $\ge$ ≥ `RELEASE_FRAME`, then removed via
  unordered swap-pop.

### `note_release_da`
Dynamic array for `note_release_t`.
- **Fields:** `items` heap pointer, `count`, `capacity`.
- **Lifecycle:**
  - Allocated on startup via `note_release_da_new()`,
  - Destroyed on exit via `note_release_da_free()`.

---

## 3. State Machine

```
               [ SPACE: start new record ]
     ┌─────────────────────────────────────────────┐
     │                                             ▼
┌──────────┐    Measure Rollover (EOB)       ┌─────────────┐
│  REPLAY  │ ◄────────────────────────────── │ WAIT_FOR_EOB│
└──────────┘                                 └─────────────┘
     ▲         [ SPACE: cancel wait ]              │
     │                                             │ Measure rolls over
     │                                             ▼
     │         [ SPACE: stop record / loop ] ┌─────────────┐
     └───────────────────────────────────────│   RECORD    │
                                             └─────────────┘
```

### State 1: `REPLAY` (Default)
- **Behavior:** 
  Loops recorded `events`.
  Maps `quant` ticks to `notes_replay` array.
  Plays active notes and releases them when tick matches event timestamp.
  Live monitor input still playable.
- **Transitions:**
 ┌ Press `KEY_SPACE` $\to$ clears `events->count = 0`,
 │ Stops all `notes_replay`,
 └ Transitions to `WAIT_FOR_EOB`.

### State 2: `WAIT_FOR_EOB` (Wait For End of Bar)
- **Behavior:** Quantization synchronizer. Waits for audio clock to cross bar
  boundary (`fmodf(beat_time, BAR_SECS)` wrap).
- **Transitions:**
  - Bar boundary crossed $\to$ snapshots all currently held `notes_monitor` keys
    into `events` at tick 0, resets `beat_time = 0`, transitions to `RECORD`.
  - Press `KEY_SPACE` $\to$ cancels recording, transitions directly to `REPLAY`.

### State 3: `RECORD`
- **Behavior:** Captures user inputs. Every key press/release on `KEY_MAP` logs
  `event_t` with current `quant` tick into `events`.
- **Transitions:** Press `KEY_SPACE` $\to$ calculates `record_bar_amount` based on final
  `quant`, resets `beat_time = 0`, transitions to `REPLAY`.

---

## 4. Variables & Lifecycle

| Variable | Scope | Type | Lifecycle & State |
|---|---|---|---|
| `KEY_MAP`             | Global | `const KeyboardKey[]` | Read-only static mapping of 15 keyboard keys to semitone slots. |
| `notes_monitor`       | Global | `note_t[15]`          | Tracks live keyboard voice states. Updated on key down/up. |
| `notes_replay`        | Global | `note_t[15]`          | Tracks sequencer playback voice states. Controlled by `events` queue. |
| `frame_count`         | Global | `size_t`              | Monotonic sample counter. Incremented by 1 per audio sample. |
| `.`                   | . | .                        |└ Master clock for attack/release envelopes. |
| `g_note_releases`     | Global | `note_release_da*`    | Active decaying voice pool. Dynamically appended and pruned. |
| `synth`               | `main` | `AudioStream`         | Raylib audio output pipeline. Pushed PCM data every frame. |
| `events`              | `main` | `event_da*`           | Dynamic buffer of recorded sequence events. |
| `beat_time`           | `main` | `float`               | Fractional clock timer (seconds). Incremented by `GetFrameTime()`. |
| `quant`               | `main` | `int`                 | Current tick index calculated from `beat_time / QUANT_SECS`. |
| `quant_for_play`      | `main` | `int`                 | Modulo-wrapped tick index within the loop length. |
| `quant_for_play_prev` | `main` | `int`                 | Previous tick index. Prevents processing identical tick |
| `.`                   | . | .                        |└ events multiple times per frame.  |
| `record_bar_amount`   | `main` | `int`                 | Loop measure count (bars). Dictates total loop duration. |
| `instrument_curr`     | `main` | `instrument_t`        | Currently selected synth generator (sawtooth by default). |
| `buffer`              | `main` | `float[2048]`         | Temporary PCM rendering chunk passed to audio device. |

---

## 5. Functions & Interactions

```
               [ Input / Keyboard / Sequencer ]
                              │
               ┌──────────────┴──────────────┐
               ▼                             ▼
         note_press()                  note_released()
               │                             │
               ▼                             ▼
        [ note_t (Active) ]         [ g_note_releases ]
               │                             │
               ▼                             ▼
         note_update()              note_release_update()
               │                             │
               └──────────────┬──────────────┘
                              ▼
                     instrument_run()
                              │
                              ▼
                      [ Output Buffer ]
```

### Waveform Generators (`instrument.c`)
- **`func_sine(float x, void *data)`**:
  Computes pure sine via `sinf(x * TWO_PI)`.

- **`func_square(float x, void *data)`**:
  Computes square wave with variable duty cycle stored in `data`.

- **`func_saw_tooth(float x, void *data)`**:
  Computes asymmetric triangle/saw wave using inflection point from `data` and `LERPF`.

- **`instrument_sine()`**, **`instrument_square()`**, **`instrument_saw_tooth()`**:
  Factory constructors returning configured `instrument_t` structs.

- **`instrument_run(instrument_t instrument, float x)`**:
  Unpacks and invokes `instrument.func(x, instrument.data)`.

### Pitch & Utility Math
- **`semitone_to_freq(float semitone)`**:
  Calculates Hz: $440.0 \times (2^{1/12})^{\text{semitone}}$.

- **`clamp_f(float f, float min, float max)`**:
  Bounds float values to range. Used for envelope stages and master limiter.

- **`peek(event_da *es)`**: Reads pointer to most recent event in dynamic array.

### Voice & Envelope Management
- **`note_press(note_t *note, int semitone, instrument_t instrument)`**:
  - Activates voice. Sets `playing = true`, records `start_frame = frame_count`,
  assigns pitch and instrument.

- **`note_released(note_t *note)`**:
  - Deactivates voice. Sets `note->playing = false`. Computes current gain level
  and appends `note_release_t` into `g_note_releases`.

- **`note_update(note_t *note)`**:
  - Evaluates active note. Calculates linear attack ramp via `(frame_count -
  note->start_frame) / ATTACK_FRAME`. Multiplies by wave output from `instrument_run()`.

- **`note_release_update(note_release_t *note_rel)`**:
  - Evaluates decaying note. Calculates cosine release curve from 
  `(frame_count - note_rel->stop_frame) / RELEASE_FRAME`. Scales by initial
  release volume and wave output.

- **`note_released_done(note_release_t *nr)`**:
  - Returns `true` when note age $\ge$ `RELEASE_FRAME`.

- **`note_releases_unordered_rm_by_idx(note_release_da *nrs, size_t idx)`**:
  - Removes finished release note in $O(1)$ by overwriting index `idx` with tail
  element and decrementing `count`.

### Master Engine (`main`)
- **Main Loop**:
  1. Polls frame timing, advances `beat_time`, updates `quant`.
  2. Executes State Machine (`REPLAY`, `WAIT_FOR_EOB`, `RECORD`).
  3. Polls keyboard input (`KEY_MAP`), updates `notes_monitor`, appends record events.
  4. Checks `IsAudioStreamProcessed(synth)`: sums monitor notes, replay notes,
     and release voices, normalizes amplitude by active voice count, fills
     `buffer`, pushes to audio device via `UpdateAudioStream()`.
  5. Renders GUI: draw state indicator, note timeline grid, loop cursor, and
     recorded event markers via Raylib graphics pipeline.
