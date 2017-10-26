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
int dp[20][14][2][12];
int shu[20];
ll dfs(int len,int pre,int pan,int flag,int p)
{
  if(len<0)
  return (p && !pan);
  if(!flag && ~dp[len][pan][p][pre]) return dp[len][pan][p][pre];
  int Max = flag?shu[len]:9;
  ll ans = 0;
  for(int i = 0;i<=Max;i++)
  {
    if(pre==1 && i==3)
    ans += dfs(len-1,i,(pan*10+i)%13,flag&& i == Max,1);
    else
    ans +=dfs(len-1,i,(pan*10+i)%13,flag && i==Max,p);
  }
  if(!flag) dp[len][pan][p][pre] = ans;
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
  return dfs(co-1,0,0,1,0);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ll a;
  clr(dp,-1);
  while(cin>>a)
  {
    cout<<slove(a)<<endl;
  }
  return 0;
}
