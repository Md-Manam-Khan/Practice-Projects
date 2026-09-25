# Smart Calculator 🧮

A C++17 console-based calculator with a menu-driven interface, input validation, colored terminal output, and automatic history logging.

---

## Features

- **Arithmetic operations** — addition, subtraction, multiplication, division.
- **Integer operations** — modulus, left shift (`<<`), right shift (`>>`), bitwise AND (`&`), bitwise OR (`|`).
- **Number system conversion** — convert between binary, octal, decimal, and hexadecimal.
- Guards against division by zero, modulus by zero, and negative shift amounts.
- Colored terminal output for menus, prompts, results, and errors.
- Input validation on every prompt — invalid input never crashes or exits the program.
- Menu loops until the user chooses to exit, so multiple calculations can be done in one run.
- Every calculation is automatically saved to `calculator_history.txt`, timestamped, in the same folder as the program.

---

## How to Compile & Run

Requires a C++17-compatible compiler (e.g. g++ 8+).

```bash
g++ -std=c++17 Smart_Calculator.cpp -o Smart_Calculator
./Smart_Calculator
```

On Windows (MinGW):

```bash
g++ -std=c++17 Smart_Calculator.cpp -o Smart_Calculator.exe
Smart_Calculator.exe
```

---

## Supported Operations

| # | Operation | Symbol |
|---|---|---|
| 1 | Addition | `+` |
| 2 | Subtraction | `-` |
| 3 | Multiplication | `*` |
| 4 | Division | `/` |
| 5 | Modulus | `%` |
| 6 | Right Shift | `>>` |
| 7 | Left Shift | `<<` |
| 8 | Bitwise AND | `&` |
| 9 | Bitwise OR | `\|` |
| 10 | Number System Conversion | — |
| 0 | Exit | — |

---

## Number System Conversion

Option `10` opens a base sub-menu:

| # | Base |
|---|---|
| 1 | Binary |
| 2 | Octal |
| 3 | Decimal |
| 4 | Hexadecimal |

Pick a source base, a target base, then enter the number in the source base (hex digits `A`-`F` are accepted in either case). The result is printed in the target base and logged the same way as every other calculation.

---

## History Logging

Every calculation appends a line to `calculator_history.txt` in the working directory, for example:

```
[2026-09-25 14:22:10] 4 + 5 = 9
[2026-09-25 14:22:18] 10 / 0 = ERROR (division by zero)
[2026-09-25 14:22:31] 5 << 2 = 20
```

The file is created automatically on first use and appended to on every subsequent run, so history is never overwritten.

---

## 🚧 Planned Updates

This project is still growing. Planned additions include:

- Trigonometric functions — `sin`, `cos`, `tan`

---

## Notes

Terminal colors use ANSI escape codes. These work out of the box on Linux, macOS, and modern Windows Terminal / PowerShell. Older `cmd.exe` versions may need `chcp` or Windows Terminal for colors to render correctly.
