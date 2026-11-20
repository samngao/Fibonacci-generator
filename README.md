# Fibonacci Series Generator

TIT 009: Structure Programming - Capstone Project

A program that prints the Fibonacci series (0 1 1 2 3 5 8 13 ...) up to a number of terms chosen by the user. Each number is the sum of the two before it. The user can choose between a **loop** method and a **recursion** method.

Written in two languages so they can be compared:

| File | Language |
|------|----------|
| `fibonacci.c` | C (main project) |
| `fibonacci.py` | Python (comparison) |

## How to run

**C**
```
gcc fibonacci.c -o fibonacci
./fibonacci
```
On Windows: `gcc fibonacci.c -o fibonacci.exe` then `fibonacci.exe`

**Python**
```
python3 fibonacci.py
```

## Sample run

```
=== Fibonacci Series Generator ===
How many terms? (1-90): 10
Method: 1) Loop  2) Recursion : 1

Fibonacci series (10 terms):
0 1 1 2 3 5 8 13 21 34
```

## Features

- Loop (iterative) and recursive methods
- Input validation: rejects letters and numbers outside 1-90
- Limit of 90 terms because larger values overflow a `long long` in C

## Research: another language that can solve this (Python)

Python can solve the same problem with less code:

- No need for `#include` or declaring variable types
- Two values can be updated in one line: `a, b = b, a + b`
- Whole numbers never overflow, so there is no 90-term limit in theory
- Invalid input is handled with `try/except` instead of clearing the input buffer

C is faster and gives more control over memory, which is why it is used to learn structured programming. Python is shorter and easier to read.

Recursion is slower than the loop in both languages because it recalculates the same terms many times.

## Group members

- Samuel Muema Ngao
