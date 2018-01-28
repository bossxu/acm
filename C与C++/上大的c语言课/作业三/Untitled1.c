#include<stdio.h>
int main()
{
    int i;
    int sum=0;
    for(i=2;i<=100;)
    {
        sum = sum+i;
        i=i+2;
    }
    printf("%d",sum);

    return 0;
}
