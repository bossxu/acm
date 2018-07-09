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
ll dp[106];
ll ans[106];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3;i<=100;i++)
  {
    dp[i] = dp[i-1]+dp[i-2];
  }
  int n;
  clr(ans,0);
  for(int i = 1;i<=100;i++)
  {
    if(dp[i]%2)
    {
      ans[i] = ans[i-1];
    }
    else
    {
      ans[i] = ans[i-1]+dp[i];
    }
  }
  int t;
  cin>>t;
  while(t--)
  {
      ll k;cin>>k;
      int op = lower_bound(dp+1,dp+100,k) - dp;
      if(dp[op] == k)
      {
        cout<<ans[op]<<endl;
      }
      else
      {
        cout<<ans[op-1]<<endl;
      }
  }

  return 0;
}
