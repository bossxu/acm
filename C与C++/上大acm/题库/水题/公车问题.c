
#include<math.h>
#include<stdio.h>
#include<string.h>

int main()
{
    int n,m;
    int a[105];
    int i,j,count,sum,t;
    while(scanf("%d%d",&n,&m)==2)
    {
        sum=0;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    t=a[i];a[i]=a[j];a[j]=t;
                }
            }
        }
        i=0;
        while(m--)
        {
            if(a[i]>0) break;
            sum-=a[i];
            i++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
