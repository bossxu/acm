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
int shu[100005];
ll dp[100005];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n,k;
  while(cin>>n>>k)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    for(int i = 1;i<n;i++)
    {
      shu[i] = abs(shu[i+1]-shu[i]);
    }
    int a,b;
    while(k--)
    {
      cin>>a>>b;
      b-=1;
      int tot = 0;
      for(int i = a;i<=b;i++)
      {
        dp[tot++] = shu[i];
      }
      //cout<<tot<<endl;
      sort(dp,dp+tot);
      ll ans = 0;
      for(int i  = tot-1;i>=0;i--)
      {
        ans += (i+1)*dp[i];
      }
      cout<<ans<<endl;

    }
  }
  return 0;
}
