#include <stdio.h>
#include <math.h>

unsigned long long factorial(unsigned int n) {
    unsigned long long res = 1;
    for (unsigned int i = 2; i <= n; i++) res *= i;
    return res;
}

int main() {
    double x, y;
    int choice;

    do {
        printf("\n--- Simple Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. x^y\n");
        printf("6. x! (x must be non-negative integer)\n");
        printf("0. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) return 1;

        if (choice == 0) break;

        if (choice == 6) {
            printf("Enter x (integer): ");
            if (scanf("%lf", &x) != 1) return 1;
            if (x < 0 || floor(x) != x) {
                printf("Invalid x for factorial.\n");
            } else {
                printf("%llu\n", factorial((unsigned int)x));
            }
            continue;
        }

        printf("Enter x and y: ");
        if (scanf("%lf %lf", &x, &y) != 2) return 1;

        switch(choice) {
            case 1: printf("Result: %.6g\n", x + y); break;
            case 2: printf("Result: %.6g\n", x - y); break;
            case 3: printf("Result: %.6g\n", x * y); break;
            case 4:
                if (y == 0) printf("Cannot divide by zero\n");
                else printf("Result: %.6g\n", x / y);
                break;
            case 5: printf("Result: %.6g\n", pow(x,y)); break;
            default: printf("Invalid option\n");
        }
    } while (choice != 0);

    return 0;
}
