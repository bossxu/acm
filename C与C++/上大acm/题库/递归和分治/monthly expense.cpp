#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using  namespace std;
int n,m;
int a[100005];
int pan(long long  mid)
{
    int i,c=1,s=0;
    for(i=0;i<n;i++)
    {
        s+=a[i];
        if(s+a[i+1] > mid )
        {
            s=0;c++;
        }
    }
    if(c>m) return 0;
    else return 1;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        int i;
        long long  l=0,r=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
              if(a[i]>l) l=a[i];
              r+=a[i];
        }
        long long mid,ans;
        while(l<r)
        {
            mid=(l+r)/2;
            if(pan( mid))
            {
            ans=mid;
             r=mid;
            }
            else
            l=mid+1;
        }
       printf("%lld\n",ans);
    }
return 0;
}
