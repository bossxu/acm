#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100
#define TURE 1
#define FALS 0
//就是那个传说中的换盘子问题，每次只能动一个盘子，小盘子必须在上面。
/*************************************
递归，所谓的递归，其实主要在于分析一步是由那几部所组成，这个看起来很难
其实就和走楼梯的问题差不多，通过分兮最后一步是由倒数第二步的哪几种可能性组成。
这是种思想，看起来代码可能很难，打出来才发现，这样做是可以的。

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
    printf("请输入你要知道的多少层汉诺塔的移动规律：\n");
    scanf("%d",&n);
    move(n,x,y,z);
    return 0;
}
