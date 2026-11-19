# Number Guessing Game 🎯

A C++17 console game where you try to guess a randomly generated number within a limited number of attempts, guided by higher/lower feedback after every guess. It started as one big `.cpp` file and is now split into one `.cpp`/`.h` pair per feature, using the same layout and menu style as [SmartyCalc](../SmartyCalc).

---

## Features

- **Menu-driven** — pick a difficulty from a numbered list with the `I choose:` prompt. `0` exits, and after every round a "Want to play another round?" menu decides whether to keep going.
- **Four modes** — Easy, Medium, Hard, and a fully Custom range/guess-count setup.
- **Streak tracking** — keeps your current win streak and your best-ever streak across rounds in the same session.
- **Hidden cheat code** — typing `ManamKnowsTheNumber` instead of a guess reveals the number without spending an attempt, for testing or just curiosity.
- **Round timer** — each round is timed and the elapsed seconds are shown when you win.
- **Full input validation** — invalid numbers, out-of-range values, and even a closed/empty input stream are handled gracefully instead of crashing or freezing.
- Split across multiple files, one `.cpp`/`.h` pair per feature, as practice for structuring a C++ project beyond a single file.

---

## How to Compile & Run

Requires a C++17-compatible compiler (e.g. g++ 8+).

```bash
g++ -std=c++17 main.CPP input.cpp rng.cpp streak.cpp praise.cpp rules.cpp play.cpp easy.cpp medium.cpp hard.cpp custom.cpp choose.cpp bye.cpp -o Number_Guessing_Game
./Number_Guessing_Game
```

On Windows (MinGW):

```bash
g++ -std=c++17 main.CPP input.cpp rng.cpp streak.cpp praise.cpp rules.cpp play.cpp easy.cpp medium.cpp hard.cpp custom.cpp choose.cpp bye.cpp -o Number_Guessing_Game.exe
Number_Guessing_Game.exe
```

All source files must be passed to the compiler together — building `main.CPP` alone will fail to link.

---

## Project Structure

| Files | What they do |
|---|---|
| `main.CPP` | Welcome banner, difficulty menu, and the "play again?" loop |
| `easy`, `medium`, `hard`, `custom` | One pair per difficulty; each one starts a round with its own limits |
| `play` | `playRound()`: the actual game (guessing loop, hints, cheat code, timer) |
| `streak` | `StreakCounter` class: current and best win streak |
| `input` | `readLL()` and `readChoice()`: validated number input |
| `praise` | `successMessage()`: the message shown on a win |
| `rng` | The shared random number generator |
| `rules` | Prints the rules once at startup |
| `choose` | The "Want to play another round?" Yes/No menu |
| `bye` | The goodbye banner |
| `color.h` | ANSI color codes (header only) |

---

## Difficulty Modes

| Mode | Range | Guesses |
|---|---|---|
| Easy | 1 – 100 | 20 |
| Medium | 1 – 1,000 | 15 |
| Hard | 1 – 10,000 | 10 |
| Custom | You choose | You choose |

---

## Why Multiple Files

Same idea as SmartyCalc:

- Each `.h` file declares what a function looks like (its signature).
- Each `.cpp` file defines what it actually does.
- `main.CPP` includes the headers and calls the functions, without needing to know how they are implemented.

Adding a new difficulty means adding one more `.cpp`/`.h` pair and one more `case` in the menu.

---

## Notes

Terminal colors use ANSI escape codes and work out of the box on Linux, macOS, and modern Windows Terminal / PowerShell.
