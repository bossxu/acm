#include<stdio.h>
int main()
{
    static int num[9]={1,12,23,34,45,56,67,68,89};
    int x1,x2,mid,n,k;x1=0;x2=8;
    scanf("%d",&n);mid=(x1+x2)/2;
    while(x1<=x2)
    {
        mid=(x1+x2)/2;
        if(num[mid]==n) break;
        if(num[mid]>n)
        {
            x2=mid-1;
        }
        else
        {
            x1=mid+1;
        }
    }

if(x1<=x2)
    {
        k=mid;
    }
else
{k=-1;}

   printf("%d",k);



    return 0;
}
