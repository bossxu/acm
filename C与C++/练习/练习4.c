#include <stdio.h>
int main()
{
    /* 定义需要计算的日期 */
    int year = 2008;
    int month = 8;
    int day = 8;
    /*
     * 请使用switch语句，if...else语句完成本题
     * 如有想看小编思路的，可以点击左侧任务中的“不会了怎么办”
     * 小编还是希望大家独立完成哦~
     */
    switch(month)
    {
        case 12:  day=day+30;
        case 11:  day=day+31;
        case 10:  day=day+30;
        case 9:   day=day+31;
        case 8:   day=day+31;
        case 7:   day=day+30;
        case 6:   day=day+31;
        case 5:   day=day+30;
        case 4:   day=day+31;
        case 3:   day=day+28;
        case 2:   day=day+31;
        case 1:  day = day;
        break;

    }
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        day=day+1;
    }
    else
    {
        day=day;
    }

    printf("2008年8月8日是该年的第%d天\n",day);









	return 0;
}







