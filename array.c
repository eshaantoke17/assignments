#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks1, marks2, marks3;
    float total, percentage;
};

int main()
{
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);   
        printf("Marks in 3 subjects: ");
        scanf("%f %f %f",
              &s[i].marks1,
              &s[i].marks2,
              &s[i].marks3);
        s[i].total = s[i].marks1 + s[i].marks2 + s[i].marks3;
        s[i].percentage = s[i].total / 3;
    }
    printf("\nStudent Results");
    for(i = 0; i < n; i++)
    {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal Marks: %.2f", s[i].total);
        printf("\nPercentage: %.2f%%", s[i].percentage);

       
        if(s[i].percentage >= 40)
            printf("\nResult: PASS\n");
        else
            printf("\nResult: FAIL\n");
    }

    return 0;
}