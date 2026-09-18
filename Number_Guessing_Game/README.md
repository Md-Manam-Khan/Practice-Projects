# Number Guessing Game 🎯

A C++17 console game where you try to guess a randomly generated number within a limited number of attempts, guided by higher/lower feedback after every guess.

---

## Features

- **Four modes** — Easy, Medium, Hard, and a fully Custom range/guess-count setup.
- **Streak tracking** — keeps your current win streak and your best-ever streak across rounds in the same session.
- **Hidden cheat code** — typing `ManamKnowsTheNumber` instead of a guess reveals the number without spending an attempt, for testing or just curiosity.
- **Round timer** — each round is timed and the elapsed seconds are shown when you win.
- **Full input validation** — invalid numbers, out-of-range values, and even a closed/empty input stream are handled gracefully instead of crashing or freezing.
- **Replay loop** — play as many rounds and switch difficulties as you like without restarting the program.

---

## How to Compile & Run

Requires a C++17-compatible compiler (e.g. g++ 8+).

```bash
g++ -std=c++17 Number_Guessing_Game.cpp -o Number_Guessing_Game
./Number_Guessing_Game
```

On Windows (MinGW):

```bash
g++ -std=c++17 Number_Guessing_Game.cpp -o Number_Guessing_Game.exe
Number_Guessing_Game.exe
```

---

## Difficulty Modes

| Mode | Range | Guesses |
|---|---|---|
| Easy | 1 – 100 | 20 |
| Medium | 1 – 1,000 | 15 |
| Hard | 1 – 10,000 | 10 |
| Custom | You choose | You choose |

---

## Notes

Terminal colors use ANSI escape codes and work out of the box on Linux, macOS, and modern Windows Terminal / PowerShell.
