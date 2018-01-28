#include<stdio.h>
#include<math.h>
int main()
{
    float shu[10],sum=0,a;
    int i,j,n;
     printf("仪器误差");
    scanf("%f",&a);
    printf("有几个数");
    scanf("%d",&n);printf("\n");
   printf("请输入那几个数\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&shu[i]);

    }
    for(i=0;i<n;i++)
    {
        sum=sum+shu[i];
    }
    float avg;
    avg=sum/n;
    float Zt,St,item=0;
    for(i=0;i<n;i++)
    {
        item=item+(shu[i]-avg)*(shu[i]-avg);
    }
    St=sqrt(item/(n-1));
    Zt=sqrt(St*St+a*a);
    printf("平均值是 %.4f,差st是 %.4f,总的误差是 %.4f",avg,St,Zt);
    return 0;
}
