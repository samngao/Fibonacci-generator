"""
Fibonacci Series Generator (Python)
TIT 009: Structure Programming - Capstone Project
Author: Samuel Muema Ngao

Same program as the C version, written in Python to compare the two languages.
Each number is the sum of the two before it: 0 1 1 2 3 5 8 13 ...
"""


def fib_recursive(n):
    """Return the nth Fibonacci number (counting from 0) using recursion."""
    if n <= 1:          # base case: stops the recursion
        return n
    return fib_recursive(n - 1) + fib_recursive(n - 2)


def fib_iterative(terms):
    """Print the first 'terms' Fibonacci numbers using a loop."""
    a, b = 0, 1                 # first two terms
    for _ in range(terms):
        print(a, end=" ")       # print the current term on the same line
        a, b = b, a + b         # shift forward: Python can swap in one line
    print()


def main():
    print("=== Fibonacci Series Generator ===")

    # Input validation: keep asking until the user enters 1 to 90
    while True:
        try:
            terms = int(input("How many terms? (1-90): "))
            if 1 <= terms <= 90:
                break
            print("Please enter a number between 1 and 90.")
        except ValueError:      # user typed letters instead of a number
            print("Please enter a number between 1 and 90.")

    choice = input("Method: 1) Loop  2) Recursion : ")

    print(f"\nFibonacci series ({terms} terms):")
    if choice == "2":
        print(" ".join(str(fib_recursive(i)) for i in range(terms)))
    else:
        fib_iterative(terms)


main()
