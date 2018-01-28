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

ll a[105];
ll dp[105];
int cmp(ll a, ll b)
{
    return a>b;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        clr(dp,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>0;j--)
            {
                dp[j]=max(dp[j],dp[j-1]^a[i]);
            }
        }
       printf("%lld\n",dp[n]);
    } 
    return 0;
}