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
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
// 知识点分解：
const int maxn =2005;
ll dp2[2005];
ll dp[maxn][maxn];
//用乘法逆元的原因在于，加减乘，都可以直接对mod进行操作，但是除法不行。
void init()
{
    int i;
    dp2[0]=1;
    for(i=1;i<=2005;i++)
    {
        dp2[i]=dp2[i-1]%mod*i%mod ;
    }
}
void exgcd(ll a,ll b,ll& d,ll& x,ll& y) // 扩展欧几里得
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv(ll a, ll p) // 乘法逆元，这是利用扩展欧几里得的方法来写的
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}
ll C(int n,int m)
{
    ll z;
    z = dp2[m]*dp2[n-m]%mod;
    z = inv(z,mod);
    z = z*dp2[n]%mod;
    return z;
}
int main()
{
    clr(dp,0);
    init();
    int i,j;
    for( i=1;i<=2000;i++)
    {
        dp[i][1]=1;
        for( j=2;j<i;j++)
        {
          dp[i][j]=dp[i-1][j]*(j-2)%mod + dp[i-1][j-1]; 
          dp[i][j]%=mod;  
        }
        dp[i][j]=1;
    }
    int n,f,b;
    int t;
    cin>>t;
    while(t--)
    {
        while(cin>>n>>f>>b)
    {
        if(f==1)
        cout<<dp[n][b]<<endl;
        else if(b==1)
        cout<<dp[n][f]<<endl;
        else
        {   
            ll ans=0;
            for( i=f;i+b<=n+1;i++)
            {
               ans+=(C(n-1,f-1)*dp[i][f]%mod)*dp[n-i+1][b]%mod;
              // cout<<C(n-1,f-1)<<endl;
               ans%=mod;
            }
            cout<<ans<<endl;
        }
    }
}

    return 0;
}