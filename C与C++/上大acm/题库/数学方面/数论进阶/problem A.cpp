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
#define mod 9973
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
// 知识点分解：dp
ll  quick(ll a,ll b)
{
    ll c=1;
    while(b>0)
    {
        if(b%2==1)
            c=c*a%mod;
        b/=2;
        a=(a%mod)*(a%mod);
    }
    return c;
}
int main()
{
    int n;
    char s[100005];
    ll dp[100005];
    while(scanf("%d",&n)==1)
    {
        scanf("%s",s);
        dp[0]=1;
        for(int i=0;i<strlen(s);i++)
        {
            dp[i+1]=(dp[i]*(s[i]-28))%mod;
        }
        for(int i=1;i<=n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b)
            {
                int t;
                t=a;
                a=b;
                b=t;
            }
            ll k= dp[b]*quick(dp[a-1],mod-2)%mod;
            printf("%lld\n",k);
        }
    }
    return 0;
}