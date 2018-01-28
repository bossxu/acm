#include<stdio.h>
int main()
{
    int a,b,sum;
    float average;

     printf("Input two integers:");
    scanf("%d%d",&a,&b);

    sum =a+b;

    average =(a+b)/2;

    printf("sum=%d\n",sum);

    printf("average=%1.1f\n",average);

    return 0;
}
