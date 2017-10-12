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
ll dp[50][15];
int shu[50];
ll dfs(int len,int pre,int flag)
{
  if(len < 0) return 1;
  if(!flag && dp[len][pre]!=-1) return dp[len][pre];
  int Max = flag?shu[len]:9;
  ll ans = 0;
  for(int i = 0;i<=Max;i++)
  {
    if(i == 4) continue;
    if(i == 2 && pre == 6) continue;
    ans += dfs(len-1,i,flag&&i==Max);
  }
  if(!flag) dp[len][pre] = ans;
  return ans;
}
ll slove(ll x)
{
  int co = 0;
  while(x)
  {
    shu[co++] = x%10;
    x/=10;
  }
  return dfs(co-1,0,1);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   ll a,b;
   clr(dp,-1);
  while(cin>>a>>b && (a!=0 || b!=0))
  {
   cout<<slove(b)-slove(a-1)<<endl;
  }
  return 0;
}
