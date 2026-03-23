#include <stdio.h>

int main() {
    float marks[5], sum = 0;
    printf("Enter five course marks (0-100):\n");
    for (int i = 0; i < 5; i++) {
        if (scanf("%f", &marks[i]) != 1) return 1;
        sum += marks[i];
    }
    for (int i = 0; i < 5; i++) {
        if (marks[i] < 40) {
            printf("Result: Fail (course %d mark %.2f < 40)\n", i + 1, marks[i]);
            return 0;
        }
    }

    float aggregate = sum / 5.0;
    printf("Aggregate: %.2f%%\n", aggregate);

    if (aggregate > 75) {
        printf("Grade: Distinguished\n");
    } else if (aggregate >= 60) {
        printf("Grade: First division\n");
    } else if (aggregate >= 50) {
        printf("Grade: Second division\n");
    } else if (aggregate >= 40) {
        printf("Grade: Third division\n");
    } else {
        printf("Grade: Fail\n");
    }

    return 0;
}
