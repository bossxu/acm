#include<stdio.h>
void pan(int n)
{
    int a[4],i,k;k=n;
    for(i=0;k!=0;i++)
    {
        a[i]=k%10;k=k/10;
    }
    int sum=0,j;
    for(j=0;j<i;j++)
    {
        sum=sum+a[j]*a[j]*a[j];
    }
    if(sum==n) printf("%d\n",n);



}
int main()
{

    int a1,a2,n;
    printf("Input m: ");scanf("%d",&a1);
    printf("Input n: ");scanf("%d",&a2);
    for(n=a1;n<=a2;n++)
    {
        pan(n);
    }
    return 0;
}

