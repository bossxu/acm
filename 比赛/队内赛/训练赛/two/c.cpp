#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
#define clr(a,x) memset(a,x,sizeof(a))
const int mod = 1e8+7;
//组合数学  注意不要一位的去看题解
//现在的你不一定很多都不会做
// 不过这个真的挺难想的
ll dp[200005];
ll quick(ll a,ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b&1) ans = ans*a%mod;
    a = a*a%mod;
    b/=2;
  }
  return ans;
}
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=200000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
ll cal(int n,int m)
{
  return dp[n]*quick(dp[n-m]*dp[m]%mod,mod-2)%mod;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,p,q;
  ll no = 0;
  ll all = 0;
  init();
  while(cin>>m>>n>>p>>q)
  {
    all = cal(m+n,n)*cal(m-p+q,q)%mod;
    no = cal(m+q,q)*cal(n+m-p,n)%mod;
    cout<<(all-no+mod)%mod<<endl;
  }
  return 0;
}
