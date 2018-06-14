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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll dp[200006];
void init()
{
  dp[1] = 1;
  dp[0] = 1;
  for(int i = 2;i<=200000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
ll quick(ll a, ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    a = a*a%mod;
    b/=2;
  }
  return res;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  //std::ios::sync_with_stdio(false);
   int t;
   cin>>t;
   int n,m;
   init();
   while(t--)
   {
     cin>>n>>m;
     n = abs(n);
     if((m-n)%2 || n>m)
     {
       cout<<0<<endl;
     }
     else
     {
       int l = (m-n)/2;
       int r = n+l;
       ll fenmu = 1;
       fenmu = fenmu*(dp[r]*dp[m-r]%mod)*quick(2,m)%mod;
       fenmu = quick(fenmu,mod-2);
       //cout<<fenmu<<endl;
       cout<<dp[m]*fenmu%mod<<endl;
     }
   }
  return 0;
}
