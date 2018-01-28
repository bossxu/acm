#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
int main()
{
    int t;
    cin>>t;
    int v[1005],w[1005];
    int dp[1005];
    int chu[1005];

    while(t--)
    {
        int n,m,k;
        while(scanf("%d%d%d",&n,&m,&k)==3)
        {
           for(int i=1;i<=n;i++)
           {
               scanf("%d",&v[i]);
           }
           for(int i=1;i<=n;i++)
           {
               scanf("%d",&w[i]);
           }
           clr(dp,0);
           clr(chu,0);
           for(int i=1;i<=n;i++)
           {
               for(int j=m;j>=w[i];j--)
               {
                   dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
                   chu[dp[j]]=1;
                   printf("%d\n",dp[j]);
               }
           }
           int i;
           for(i=dp[m];i>0 ;i--)
           {
               if(chu[i]>0) k--;
               if(k==0) 
               {
                   printf("%d\n",i);
                   break;
               }
           }
           if(i==0) printf("0\n");

        }
    }
    return 0;
}