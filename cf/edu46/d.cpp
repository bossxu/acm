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
const int maxn = 1e9+7;
const int mod = 998244353;
#define clr(a,x) memset(a,x,sizeof(a))
ll shu[1005];
ll dp[1005];
ll C[1005][1005];
  void init()
  {
      C[0][0] = 1;
      C[1][0] = C[1][1] = 1;
      for(int i = 2; i <= 1000; i++) {
          C[i][0] = 1;
          for(int j = 1; j <= i; j++)
              C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
      }
  }
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  init();
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
      cin>>shu[i];
    clr(dp,0);
    dp[n+1] = 1;
    ll num = 0;
    for(int i = n;i>=1;i--)
    {
      if(shu[i]>0){
      for(int j = i+shu[i]+1;j<=n+1;j++)
      {
        if(j-i >= shu[i] && shu[i]>=1)
          dp[i] = (dp[i]+dp[j]*C[j-i-1][shu[i]]%mod)%mod;
      }
      num = (num+dp[i])%mod;
    }
    }
    cout<<num<<endl;
  }
  return 0;
}
