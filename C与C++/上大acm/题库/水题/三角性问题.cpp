#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    int a[52],dp[52];
    int i,j,s,k;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+m);
        k=1000;
        for(i=0;i<=m-n;i++)
        {
            if(k>a[i+n-1]-a[i]) k=a[i+n-1]-a[i];
        }
        printf("%d\n",k);
    }
    return 0;
}
