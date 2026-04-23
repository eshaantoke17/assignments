#include <stdio.h>

int add(int x,int y);
int sub(int x,int y);
int mul(int x,int y);
int divi(int x,int y);

int add(int x,int y)
{
    printf("The addition is %d\n", x+y);
}

int sub(int x,int y)
{
    printf("The subtraction is %d\n", x-y);
}

int mul(int x,int y)
{
    printf("The multiplication is %d\n", x*y);
}

int divi(int x,int y)
{
    if(y==0)
        printf("Division by zero not possible\n");
    else
        printf("The division is %d\n", x/y);
}

int main()
{
    int x,y,ch;

    printf("Enter two numbers: ");
    scanf("%d%d",&x,&y);

    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");

    printf("Enter your choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            add(x,y);
            break;

        case 2:
            sub(x,y);
            break;

        case 3:
            mul(x,y);
            break;

        case 4:
            divi(x,y);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}