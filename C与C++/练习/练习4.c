#include <stdio.h>
int main()
{
    /* ������Ҫ��������� */
    int year = 2008;
    int month = 8;
    int day = 8;
    /*
     * ��ʹ��switch��䣬if...else�����ɱ���
     * �����뿴С��˼·�ģ����Ե����������еġ���������ô�족
     * С�໹��ϣ����Ҷ������Ŷ~
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

    printf("2008��8��8���Ǹ���ĵ�%d��\n",day);









	return 0;
}







