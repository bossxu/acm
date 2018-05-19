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
ll shu[5007];
ll dp[5005][5005];
ll ans[5005][5005];
int n;
void init()
{
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;i+j<=n;j++)
    {
      dp[j][j+i] = dp[j][j+i-1]^dp[j+1][i+j];
    }
  }
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;i+j<=n;j++)
    {
      ans[j][j+i] = max(dp[j][j+i],max(ans[j][i+j-1],ans[j+1][i+j]));
    }
  }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      dp[i][i] = shu[i];
      ans[i][i] = shu[i];
    }
    init();
    int q;
    cin>>q;
    int l,r;
    while(q--)
    {
      cin>>l>>r;
      cout<<ans[l][r]<<endl;
    }
  }
  return 0;
}
