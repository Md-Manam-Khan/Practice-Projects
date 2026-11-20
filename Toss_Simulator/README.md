# Toss Simulator 🪙

A C++17 console app that simulates coin tosses for any number of participants, with multiple game modes and a live flipping animation. It started as one big `.cpp` file and is now split into one `.cpp`/`.h` pair per feature, using the same layout and menu style as [SmartyCalc](../SmartyCalc).

---

## Features

- **Menu-driven** — pick a mode from a numbered list with the `I choose:` prompt. `0` exits, and after every game a "Want to play another round?" menu decides whether to keep going.
- **Regular toss** — one flip decides the winner among any number of participants.
- **Ranked elimination** — tosses repeat until every participant has a final ranking, not just first place.
- **Best of series** — head-to-head match between two players over any odd number of rounds (best of 3, 5, 7, etc.), not hardcoded to 3.
- **Head-to-head stats** — simulate thousands of tosses between two players instantly and see win percentages.
- Colored terminal output and a live flip animation.
- Input validation on every prompt — invalid input never crashes the program, and a closed input stream exits cleanly instead of looping forever.
- Every result is automatically saved to `toss_results.txt`, timestamped, in the same folder as the program.
- Split across multiple files, one `.cpp`/`.h` pair per feature, as practice for structuring a C++ project beyond a single file.

---

## How to Compile & Run

Requires a C++17-compatible compiler (e.g. g++ 8+).

```bash
g++ -std=c++17 main.CPP input.cpp names.cpp rng.cpp stamp.cpp logger.cpp anim.cpp banner.cpp rules.cpp toss.cpp ranked.cpp series.cpp stats.cpp choose.cpp bye.cpp -o Toss_Simulator
./Toss_Simulator
```

On Windows (MinGW):

```bash
g++ -std=c++17 main.CPP input.cpp names.cpp rng.cpp stamp.cpp logger.cpp anim.cpp banner.cpp rules.cpp toss.cpp ranked.cpp series.cpp stats.cpp choose.cpp bye.cpp -o Toss_Simulator.exe
Toss_Simulator.exe
```

All source files must be passed to the compiler together — building `main.CPP` alone will fail to link.

---

## Project Structure

| Files | What they do |
|---|---|
| `main.CPP` | Welcome banner, mode menu, and the "play again?" loop |
| `toss`, `ranked`, `series`, `stats` | One pair per mode: regular toss, ranked elimination, best of series, head-to-head stats |
| `input` | `readInt()`, `readOddInt()` and `readChoice()`: validated number input |
| `names` | `readName()` and `readParticipants()`: name input |
| `rng` | `RNG` class: the shared random number generator |
| `anim` | The live flipping animation |
| `banner` | The `===== result =====` banner used for winners and standings |
| `logger`, `stamp` | Writes timestamped lines to `toss_results.txt` |
| `rules` | Prints the rules once at startup |
| `choose` | The "Want to play another round?" Yes/No menu |
| `bye` | The goodbye banner |
| `color.h` | ANSI color codes (header only) |

---

## Modes

| Mode | Players | Description |
|---|---|---|
| Regular toss | 2+ | Single flip, one winner |
| Ranked elimination | 2+ | Repeated tosses build a full ranking from 1st to last |
| Best of series | 2 | First to win the majority of N rounds takes the series |
| Head-to-head stats | 2 | Bulk-simulate tosses and see win distribution |

---

## Result Logging

Every toss, elimination, series, or stats run appends a line to `toss_results.txt` in the working directory, for example:

```
[2026-09-17 18:43:34] Regular toss | participants: 2 | winner: Alice
[2026-09-17 18:43:34] Head-to-head stats | Alice vs Bob | tosses: 10 | Alice: 5 Bob: 5
[2026-09-17 18:43:38] Ranked elimination | participants: 3 | standings: 1)B 2)A 3)C
```

The file is created automatically on first use and appended to on every subsequent run, so history is never overwritten.

---

## Why Multiple Files

Same idea as SmartyCalc:

- Each `.h` file declares what a function looks like (its signature).
- Each `.cpp` file defines what it actually does.
- `main.CPP` includes the headers and calls the functions, without needing to know how they are implemented.

Adding a new mode means adding one more `.cpp`/`.h` pair and one more `case` in the menu.

---

## Notes

Terminal colors use ANSI escape codes. These work out of the box on Linux, macOS, and modern Windows Terminal / PowerShell. Older `cmd.exe` versions may need `chcp` or Windows Terminal for colors to render correctly.
