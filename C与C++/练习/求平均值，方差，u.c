#include<stdio.h>
#include<math.h>
int main()
{
    float shu[10],sum=0,a;
    int i,j,n;
     printf("�������");
    scanf("%f",&a);
    printf("�м�����");
    scanf("%d",&n);printf("\n");
   printf("�������Ǽ�����\n");
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
    printf("ƽ��ֵ�� %.4f,��st�� %.4f,�ܵ������ %.4f",avg,St,Zt);
    return 0;
}
