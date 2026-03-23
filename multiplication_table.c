#include <stdio.h>

int main() {
    int num, i, limit;
    printf("Enter the number to generate table for: ");
    if (scanf("%d", &num) != 1) return 1;
    printf("Enter the limit: ");
    if (scanf("%d", &limit) != 1) return 1;

    printf("Multiplication table for %d up to %d:\n", num, limit);
    for (i = 1; i <= limit; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    return 0;
}
