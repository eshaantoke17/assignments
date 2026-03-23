#include <stdio.h>

int main() {
    double basic;
    printf("Enter basic pay: ");
    if (scanf("%lf", &basic) != 1) return 1;

    double hra = 0.10 * basic;
    double ta = 0.05 * basic;
    double gross = basic + hra + ta;
    double prof_tax = 0.02 * gross;
    double net = gross - prof_tax;

    printf("Basic Pay: %.2f\n", basic);
    printf("HRA (10%%): %.2f\n", hra);
    printf("TA (5%%): %.2f\n", ta);
    printf("Gross Salary: %.2f\n", gross);
    printf("Professional Tax (2%%): %.2f\n", prof_tax);
    printf("Net Salary: %.2f\n", net);

    return 0;
}
