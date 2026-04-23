#include<stdio.h>

int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}

int main()
{
    int n,i,f=1;

    printf("Enter number : ");
    scanf("%d",&n);

    if(n<0)
    {
        printf("Factorial not possible");
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            f=f*i;
        }

        printf("Factorial without recursion = %d\n",f);
        printf("Factorial with recursion = %d",fact(n));
    }

    return 0;
}
