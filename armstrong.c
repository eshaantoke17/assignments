#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter a three-digit number: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n < 100 || n > 999) {
        printf("Input must be a three-digit number.\n");
        return 0;
    }

    int temp = n, sum = 0;
    while (temp > 0) {
        int d = temp % 10;
        sum += d * d * d;
        temp /= 10;
    }

    if (sum == n)
        printf("%d is an Armstrong number.\n", n);
    else
        printf("%d is not an Armstrong number.\n", n);

    return 0;
}
