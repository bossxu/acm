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
int dp[1005];
int main()
{
    int t;
    cin>>t;
    int jia[1005],zhong[1005];
    while(t--)
    {
        int n,v;
        while(scanf("%d%d",&n,&v)==2)
        {
            clr(dp,0);
           for(int i=1;i<=n;i++)
             scanf("%d",&jia[i]);
           for(int i=1;i<=n;i++)
             scanf("%d",&zhong[i]);

            for(int i=1;i<=n;i++)
            {
                for(int j=v;j>=zhong[i];j--)
                {
                    dp[j]=max(dp[j],dp[j-zhong[i]]+jia[i]);
                }
            }   
           printf("%d\n",dp[v]);
        }
    }
    return 0;
}