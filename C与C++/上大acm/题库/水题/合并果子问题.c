#include<stdio.h>

int main()
{
    int n,i,j,t;
    int a[10005];
    int sum,F;
    while(scanf("%d",&n)==1)
    {
        F=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<n;i++)//     ÅÅÐò
        {
            for(j=i+1;j<=n;j++)
            {
                if(a[i]>a[j])
                {
                    t=a[i];a[i]=a[j];a[j]=t;
                }
            }
        }
        sum=a[1];
        for(i=2;i<=n;i++)
        {
            sum=sum+a[i];
            F+=sum;
        }
        printf("%d\n",F);
    }
    return 0;
}

