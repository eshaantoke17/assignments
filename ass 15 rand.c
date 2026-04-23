#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i;

    printf("Enter how many numbers : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("%d\n",rand());
    }

    return 0;
}