#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100
#define TURE 1
#define FALS 0
//�����Ǹ���˵�еĻ��������⣬ÿ��ֻ�ܶ�һ�����ӣ�С���ӱ��������档
/*************************************
�ݹ飬��ν�ĵݹ飬��ʵ��Ҫ���ڷ���һ�������Ǽ�������ɣ��������������
��ʵ�ͺ���¥�ݵ������࣬ͨ���������һ�����ɵ����ڶ������ļ��ֿ�������ɡ�
������˼�룬������������ܺ��ѣ�������ŷ��֣��������ǿ��Եġ�

**************************************/

void move(int n,char x,char y,char z)
{

    if(n==1)
        printf("%c-->%c\n",x,z);
    else
    {
        move(n-1,x,z,y);
        printf("%c-->%c\n",x,z);
        move(n-1,y,x,z);
    }
}
int main()
{
    char x='x',y='y',z='z';
    int n;
    printf("��������Ҫ֪���Ķ��ٲ㺺ŵ�����ƶ����ɣ�\n");
    scanf("%d",&n);
    move(n,x,y,z);
    return 0;
}
