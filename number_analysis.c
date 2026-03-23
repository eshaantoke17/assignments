#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

unsigned long long factorial(unsigned int n) {
    unsigned long long res = 1;
    for (unsigned int i = 2; i <= n; i++) res *= i;
    return res;
}

void prime_factors(int n) {
    if (n <= 1) { printf("None\n"); return; }
    int first = 1;
    while (n % 2 == 0) {
        if (!first) printf(" x "); printf("2"); first = 0;
        n /= 2;
    }
    for (int p = 3; p <= sqrt(n); p += 2) {
        while (n % p == 0) {
            if (!first) printf(" x "); printf("%d", p); first = 0;
            n /= p;
        }
    }
    if (n > 1) {
        if (!first) printf(" x "); printf("%d", n);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n < 0) {
        printf("Negative number not supported for factorial and sqrt.\n");
    } else {
        printf("Square root: %.6g\n", sqrt((double)n));
        printf("Square: %lld\n", (long long)n * n);
        printf("Cube: %lld\n", (long long)n * n * n);
        printf("Factorial: %llu\n", factorial((unsigned int)n));
    }

    printf("Prime check: %s\n", is_prime(n) ? "Prime" : "Not prime");
    printf("Prime factors: "); prime_factors(abs(n));

    return 0;
}
