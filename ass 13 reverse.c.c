#include <stdio.h>

int main()
{
    int num, digit;

    printf("Enter a number: ");
    scanf("%d", &num);
if(num == 0)
    {
        printf("Digits in reverse order: 0");
        return 0;
    }
 if(num < 0)
    {
        num = -num;
    }

    printf("Digits in reverse order: ");

    while(num > 0)
    {
        digit = num % 10;
        printf("%d ", digit);
        num = num / 10;
    }
    return 0;
}