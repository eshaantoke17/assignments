#include <stdio.h>

int main() {
    int choice;
    double a, b;

    do {
        printf("\n--- Basic Arithmetic Menu ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus (integers)\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) return 1;

        if (choice == 0) break;

        printf("Enter two numbers: ");
        if (scanf("%lf %lf", &a, &b) != 2) return 1;

        switch (choice) {
            case 1:
                printf("Result: %.2f\n", a + b);
                break;
            case 2:
                printf("Result: %.2f\n", a - b);
                break;
            case 3:
                printf("Result: %.2f\n", a * b);
                break;
            case 4:
                if (b == 0) printf("Error: Division by zero\n");
                else printf("Result: %.2f\n", a / b);
                break;
            case 5:
                if ((int)b == 0) {
                    printf("Error: Modulus by zero\n");
                } else {
                    printf("Result: %d\n", (int)a % (int)b);
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    printf("Exiting...\n");
    return 0;
}
