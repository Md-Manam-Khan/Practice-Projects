# SmartyCalc 🧮

A console calculator written in C++, and my first multi-file C++ project. It started as a simple `add(x, y)` split across `main.CPP`, `add.cpp`, and `add.h` to learn how declarations, definitions, and linking work — and it's growing from there.

---

## Features

- **Menu-driven** — choose an operation from a numbered list, then enter the values it needs.
- **Input validation** — an invalid menu choice re-prompts instead of crashing.
- Split across multiple files (`main.CPP`, `add.cpp`, `add.h`) as practice for structuring a C++ project beyond a single `.cpp` file.

## Planned

This is a work in progress. Next up:

- Subtraction, multiplication, division
- Trigonometry — sin, cos, tan
- Geometry — area and volume for common shapes
- Time conversion — 12-hour to 24-hour format
- More robust input handling (rejecting non-numeric input without crashing)

---

## How to Compile & Run

Requires a C++ compiler (e.g. g++, MinGW on Windows).

```bash
g++ main.CPP add.cpp -o SmartyCalc
./SmartyCalc
```

On Windows:

```bash
g++ main.CPP add.cpp -o SmartyCalc
.\SmartyCalc
```

Both source files must be passed to the compiler together — building `main.CPP` alone will fail to link.

---

## Why Multiple Files

This project exists to practice splitting C++ code across files:

- `add.h` declares what a function looks like (its signature).
- `add.cpp` defines what it actually does.
- `main.CPP` includes the header and calls the function, without needing to know how it's implemented.

As more operations are added, each will likely get its own `.cpp`/`.h` pair, following the same pattern.

---

## Notes

Built and tested on Windows with MinGW g++. Early-stage project — expect the structure and menu to change as more operations are added.
