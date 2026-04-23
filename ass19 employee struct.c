#include <stdio.h>
#include <string.h>

struct EMPLOYEE {
    char name[50], desig[50], gender[10], doj[20];
    float salary;
};

int main() {
    int n, i, male = 0, female = 0;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct EMPLOYEE e[n];

    for (i = 0; i < n; i++) {
        printf("Enter Name, Designation, Gender, DOJ, Salary: ");
        scanf("%s %s %s %s %f", e[i].name, e[i].desig, e[i].gender, e[i].doj, &e[i].salary);
        if (strcmp(e[i].gender, "Male") == 0) male++;
        else female++;
    }

    printf("\nTotal employees = %d\nMale = %d, Female = %d", n, male, female);
    printf("\nSalary > 10000: ");
    for (i = 0; i < n; i++) if (e[i].salary > 10000) printf("%s ", e[i].name);
    printf("\nAsst Managers: ");
    for (i = 0; i < n; i++) if (strcmp(e[i].desig, "AsstManager") == 0) printf("%s ", e[i].name);
    
    return 0;
}