#include <stdio.h>

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int smallest_divisor(int n) {
    if (n < 0) n = -n;
    if (n <= 1) return n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return i;
    }
    return n;
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) return 1;

    printf("Smallest divisor of %d: %d\n", x, smallest_divisor(x));
    printf("Smallest divisor of %d: %d\n", y, smallest_divisor(y));
    printf("GCD(%d, %d) = %d\n", x, y, gcd(x, y));
    return 0;
}
