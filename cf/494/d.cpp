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
#define clr(a,x) memset(a,x,sizeof(a))
int shu[42];
int dp[42];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  while(cin>>n>>k)
  {
    clr(shu,0);
    clr(dp,0);
    ll a;
    for(int i = 1;i<=n;i++)
    {
      cin>>a;
      for(int j = 0;j<32;j++)
      {
        if(a == (1<<j))
        {
          dp[j]++;
        }
      }
    }
    while(k--)
    {
      ll it;
      cin>>it;
      int ans = 0;
      int cnt = 0;
      for(int i = 31;i>=0;i--)
      {
          cnt*=2;
          if(it & (1<<i))
          {
            cnt++;
          }
          ans+=min(cnt,dp[i]);
          cnt-=min(cnt,dp[i]);
      }
      if(cnt)
      {
        cout<<-1<<endl;
      }
      else
      {
        cout<<ans<<endl;
      }

    }
  }
  return 0;
}
