# Toss Simulator 🪙

A C++17 console app that simulates coin tosses for any number of participants, with multiple game modes and a live flipping animation.

---

## Features

- **Regular toss** — one flip decides the winner among any number of participants.
- **Ranked elimination** — tosses repeat until every participant has a final ranking, not just first place.
- **Best of series** — head-to-head match between two players over any odd number of rounds (best of 3, 5, 7, etc.), not hardcoded to 3.
- **Head-to-head stats** — simulate thousands of tosses between two players instantly and see win percentages.
- Colored terminal output and a live flip animation.
- Input validation on every prompt — invalid input never crashes the program or exits it.
- Replay any mode without restarting the whole program.
- Every result is automatically saved to `toss_results.txt`, timestamped, in the same folder as the program.

---

## How to Compile & Run

Requires a C++17-compatible compiler (e.g. g++ 8+).

```bash
g++ -std=c++17 Toss_Simulator.cpp -o Toss_Simulator
./Toss_Simulator
```

On Windows (MinGW):

```bash
g++ -std=c++17 Toss_Simulator.cpp -o Toss_Simulator.exe
Toss_Simulator.exe
```

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

## Notes

Terminal colors use ANSI escape codes. These work out of the box on Linux, macOS, and modern Windows Terminal / PowerShell. Older `cmd.exe` versions may need `chcp` or Windows Terminal for colors to render correctly.
