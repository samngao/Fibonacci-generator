/*
 * Fibonacci Series Generator (C)
 * TIT 009: Structure Programming - Capstone Project
 * Author: Samuel Muema Ngao
 *
 * The Fibonacci series starts with 0 and 1. Every next number is the
 * sum of the two numbers before it: 0 1 1 2 3 5 8 13 ...
 * The user chooses how many terms to print and which method to use
 * (loop or recursion).
 */

#include <stdio.h>   /* needed for printf and scanf */

/* RECURSIVE METHOD
 * Returns the nth Fibonacci number (counting from 0).
 * The function calls itself for the two previous terms. */
long long fibRecursive(int n) {
    /* Base case: the 0th term is 0 and the 1st term is 1.
     * This stops the function from calling itself forever. */
    if (n <= 1)
        return n;

    /* Recursive case: add the two previous terms */
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

/* LOOP (ITERATIVE) METHOD
 * Prints the first 'terms' Fibonacci numbers using a for loop. */
void fibIterative(int terms) {
    long long a = 0;   /* current term, starts at 0 */
    long long b = 1;   /* next term, starts at 1 */
    long long next;    /* temporary holder for the sum */

    for (int i = 0; i < terms; i++) {
        printf("%lld ", a);   /* print the current term */
        next = a + b;         /* add the two numbers */
        a = b;                /* move forward: old b becomes current */
        b = next;             /* the sum becomes the next term */
    }
    printf("\n");
}

int main(void) {
    int terms;    /* how many terms the user wants */
    int choice;   /* 1 = loop, 2 = recursion */

    printf("=== Fibonacci Series Generator ===\n");

    /* INPUT VALIDATION
     * Keep asking until the user enters a number from 1 to 90.
     * 90 is the limit because bigger terms overflow a long long. */
    do {
        printf("How many terms? (1-90): ");

        /* scanf returns 1 when it successfully reads one integer.
         * If the user typed letters, it returns something else. */
        if (scanf("%d", &terms) != 1) {
            while (getchar() != '\n');   /* throw away the bad input */
            terms = 0;                   /* force the loop to ask again */
        }

        if (terms < 1 || terms > 90)
            printf("Please enter a number between 1 and 90.\n");
    } while (terms < 1 || terms > 90);

    /* Let the user choose the method */
    printf("Method: 1) Loop  2) Recursion : ");
    scanf("%d", &choice);

    printf("\nFibonacci series (%d terms):\n", terms);

    if (choice == 2) {
        /* Recursion gives one term at a time, so we call it for
         * positions 0, 1, 2, ... up to terms-1 */
        for (int i = 0; i < terms; i++)
            printf("%lld ", fibRecursive(i));
        printf("\n");
    } else {
        /* Any other choice uses the loop method */
        fibIterative(terms);
    }

    return 0;
}
