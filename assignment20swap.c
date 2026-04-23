// Online C compiler to run C program online
#include <stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main() {
    int x,y;
    printf("enter the two nos");
    scanf("%d%d",&x,&y);
    swap(&x,&y);
    printf("after swappong =%d\n%d",x,y);
    return 0;
}