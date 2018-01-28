#include<stdio.h>
int tiao(int k[],int n)
{

    int i,j,t;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(k[j]>k[j+1])
            {
              t=k[j];
              k[j]=k[j+1];
              k[j+1]=t;
            }
        }
    }



}
int main()
{
    int x1,x2,a1[100];int i,j;
    printf("Enter n: ");scanf("%d",&x1);
    printf("Enter %d integers: ",x1);
    for(i=0;i<x1;i++)
    {
        scanf("%d",&a1[i]);
    }
    printf("Enter m: ");scanf("%d",&x2);printf("Enter %d integers: ",x2);
    for(;i<x1+x2;i++)
    {
        scanf("%d",&a1[i]);
    }
    tiao(a1,x1+x2);
    for(i=0;i<x1+x2;i++)
    {
        printf("%4d",a1[i]);
    }

    return 0;
}
