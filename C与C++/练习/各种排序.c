#include<stdio.h>
void pai_1(int a[],int n)//冒泡排序
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j]) //从小到大排
            {
                t=a[i];a[i]=a[j];a[j]=t;
            }
        }
    }
}
void pai_2(int a[],int n)//选择排序法
{
    int i,j,k,min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)//从小到大
        {
          if(a[j]<a[min]) min=j;
        }
        k=a[i];a[i]=a[min];a[min]=k;
    }
}
void pai_3(int a[],int n)//插入排序法
{
    int i,j,k;
    for(i=0;i<n;i++)
        {
            for(j=i;j!=0;j--)
        {
            if(a[j]<a[j-1])
                {
                     k=a[j-1];a[j-1]=a[j];a[j]=k;
                }
        }
        }
}
void show(int a[],int n)
{
    int i;
    for(i=0;i<n;i++) printf("%2d",a[i]);
}
void cha_1(int a[],int n,int shu)//二分法，不熟，要多写；
{
    int i,j,mid,min,max;
    max=n-1;min=0;
    while (max>min)
    {
        mid=(max+min)/2;
        if(a[mid]==shu) break;
        if(a[mid]<shu) min=mid+1;
        else  max=min-1;
    }
    if(max<=min) printf("瞎鸡巴输数字\n");
    else  printf("这个数是数组的第%d个数",mid+1);

}
void cha_2(int a[],int n,int shu)//逐项查找法
{
   int i;
   for(i=0;i<n;i++)
   {
       if(shu==a[i]) {printf("这个数是数组的第%d个数",i+1);return;}
   }
   printf("瞎鸡巴输数字\n");
}
int main()
{
    int a[6]={5,8,1,2,3,9},n,it,shu;
    show(a,6);
    printf("\n上面是原始数组的样子\n");
    printf("请选择要排序的方式：\n1:冒泡排序法\t2:选择排序法\t3:插入排序法\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:pai_1(a,6);break;
        case 2:pai_2(a,6);break;
        case 3:pai_3(a,6);break;
    }

    printf("排序已经结束，请选择剩下要做的事：");
    while(1)
    {
        printf("\n你有以下几个选择：\n1:展示排好的数组\t2：查找\t3：按0退出系统\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: show(a,6);break;
            case 2:printf("查找的方法有以下几种做法：\n1：二分法找\t2：逐项查找\t3：你要是按错了就按0退出\n");
                    scanf("%d",&it);
                    if(it==0) break;
                    printf("请输入要找的数：");scanf("%d",&shu);
                    switch(it)
                    {
                        case 1:cha_1(a,6,shu);break;
                        case 2:cha_2(a,6,shu);break;
                    }
        }
         if(n==0) {printf("\n感谢使用复习常见软件；\n再见");break;}
    }
    return 0;
}
