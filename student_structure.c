#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    int roll;
    int age;
    float marks[5];
    float total;
    float percentage;
};

int main() {
    int n;
    printf("How many students? ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d details:\n", i + 1);
        printf("Name: ");
        scanf(" "); // eat newline
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Roll no: ");
        scanf("%d", &students[i].roll);
        printf("Age: ");
        scanf("%d", &students[i].age);

        students[i].total = 0;
        for (int j = 0; j < 5; j++) {
            printf("Mark for course %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }
        students[i].percentage = students[i].total / 5.0f;
    }

    printf("\n--- Student Results ---\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll: %d, Age: %d, Total: %.2f, Percentage: %.2f\n",
               students[i].name, students[i].roll, students[i].age,
               students[i].total, students[i].percentage);
    }

    return 0;
}
