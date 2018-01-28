#include<stdio.h>
int main()
{
    int year,month,day;
    printf("Input year, month, day: ");
    scanf("%d",&year);scanf("%d",&month);scanf("%d",&day);

    printf("Days of year: %d",pan(year,month,day));


    return 0;
}
int pan(int a,int b,int c)
{
    int day=0,i=0;
    int ku[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
    int item ; if((a%4==0&&a%100!=0)||(a%400==0)) item=1;else item=0;
    for(;i<b;i++)
    {
        day=day+ku[item][i];
    }
    day=day+c;

    return day;
}
