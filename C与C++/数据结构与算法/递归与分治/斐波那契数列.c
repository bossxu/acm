#include<stdio.h>
#define MAXSIZE 100
int Digui(int i)
{
    if(i<2) return i==0?0:1;
    return Digui(i-1)+Digui(i-2);
}
int main()
{

   /* {//迭代的算法
    int shu[100];
    int i=0,j;
    shu[0]=0;
    shu[1]=1;
    for(i=2;i<MAXSIZE;i++)
    {
        shu[i]=shu[i-2]+shu[i-1];
    }
    printf("请输入你要显示的前多少个数：\n");
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
        printf("第%d个数为：%d      ",i+1,shu[i]);
        if(i%3==0&&i!=0) putchar('\n');
    }
    }*/
   {//递归的算法
       int i ,j;
      printf("请输入你要显示的第多少个数：\n");
      scanf("%d",&i);
      printf("第%d个数的值为：%d",i,Digui(i));
   }
    return 0;
}
