#include <stdio.h>

// Iterative function to calculate factorial
int factorial_iterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Recursive function to calculate factorial
int factorial_recursive(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial_recursive(n - 1);
    }
}

int main() {
    int num = 5;

    printf("Factorial of %d (iterative): %d\n", num, factorial_iterative(num));

    // Intentional bug: Incorrect initial call to factorial_recursive
    printf("Factorial of %d (recursive): %d\n", num, factorial_recursive(num - 1));

    return 0;
}
