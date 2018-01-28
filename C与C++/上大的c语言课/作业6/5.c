#include<stdio.h>
int fib(int k);
int main()
{
    int n,m;
    printf("Input m: ");scanf("%d",&m);
    printf("Input n: ");scanf("%d",&n);
    int i=1,it;
    do
    {
        it=fib(i);if(it>=m) printf("%d ",it);
        i++;
        if(fib(i)>n) break;
    }while(1);


    return 0;
}
int fib(int k)
{
    int num[1000],i;
    num[0]=0;num[1]=1;
    for(i=2;i<=k;i++)
    {
        num[i]=num[i-1]+num[i-2];
    }
    return num[k];
}
