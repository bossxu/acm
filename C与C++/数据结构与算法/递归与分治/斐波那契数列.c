#include<stdio.h>
#define MAXSIZE 100
int Digui(int i)
{
    if(i<2) return i==0?0:1;
    return Digui(i-1)+Digui(i-2);
}
int main()
{

   /* {//�������㷨
    int shu[100];
    int i=0,j;
    shu[0]=0;
    shu[1]=1;
    for(i=2;i<MAXSIZE;i++)
    {
        shu[i]=shu[i-2]+shu[i-1];
    }
    printf("��������Ҫ��ʾ��ǰ���ٸ�����\n");
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
        printf("��%d����Ϊ��%d      ",i+1,shu[i]);
        if(i%3==0&&i!=0) putchar('\n');
    }
    }*/
   {//�ݹ���㷨
       int i ,j;
      printf("��������Ҫ��ʾ�ĵڶ��ٸ�����\n");
      scanf("%d",&i);
      printf("��%d������ֵΪ��%d",i,Digui(i));
   }
    return 0;
}
