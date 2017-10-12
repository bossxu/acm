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
int shu[50];
ll dp[50][15];
ll dfs(int len ,int pre ,int flag)
{
  if(len<0) return 1;
  if(!flag && dp[len][pre]!=-1) return dp[len][pre];
  int Max = flag?shu[len]:9;
  ll ans=0;
  for(int i = 0;i<=Max;i++)
  {
    if(pre == 4 && i==9) continue;
    ans+=dfs(len-1,i,flag && i==Max);
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
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  clr(dp,-1);
  while(t--)
  {
    ll a;
    cin>>a;
    cout<<a-slove(a)+1<<endl;
  }

  return 0;
}
