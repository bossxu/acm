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
int shu[40];
ll dp[2][500000];
int tot[2];
ll m;
void dfs(int st,ll pre,int end,int i)
{
  if(st>end) return;
  dp[i][tot[i]++] = (pre+shu[st])%m;
  dfs(st+1,pre,end,i);
  dfs(st+1,(pre+shu[st])%m,end,i);
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n>>m)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      shu[i]%=m;
    }
    ll ans = 0;
    clr(tot,0);
    dfs(1,0,n/2,0);
    dfs(n/2+1,0,n,1);
    sort(dp[0],dp[0]+tot[0]);
    sort(dp[1],dp[1]+tot[1]);
  //  cout<<tot[0]<<" "<<tot[1]<<endl;
    for(int i = 0;i<tot[0];i++)
    {
      ans = max(dp[0][i],ans);
    }
    for(int i = 0;i<tot[1];i++)
    {
      ans = max(dp[1][i],ans);
    }
        for(int i = 0;i<tot[0];i++)
    {
      int ok = lower_bound(dp[1],dp[1]+tot[1],m-dp[0][i]) - dp[1];
      if(ok != 0) ok--;
      //cout<<dp[1][ok]<<" "<<dp[0][i]<<endl;
      ans = max(ans,(dp[0][i]+dp[1][ok])%m);
      ans = max(ans,(dp[0][i]+dp[1][tot[1]-1])%m);
    }
    cout<<ans<<endl;
  }
  return 0;
}
