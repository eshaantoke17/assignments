#include <stdio.h>

unsigned long long factorial_recursive(unsigned int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial_recursive(n - 1);
}

unsigned long long factorial_iterative(unsigned int n) {
    unsigned long long res = 1;
    for (unsigned int i = 2; i <= n; i++) res *= i;
    return res;
}

int main() {
    unsigned int n;
    printf("Enter a non-negative integer: ");
    if (scanf("%u", &n) != 1) return 1;

    printf("Factorial recursively: %llu\n", factorial_recursive(n));
    printf("Factorial iteratively: %llu\n", factorial_iterative(n));
    return 0;
}
