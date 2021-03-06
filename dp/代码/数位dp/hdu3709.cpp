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
int shu[20];
ll dp[20][20][1800];
ll dfs(int len, int sum,int point,int flag)
{
  if(len == 0 )
  return sum == 0;
  if(!flag && ~dp[len][point][sum]) return dp[len][point][sum];
  int Max = flag?shu[len]:9;
  ll ans = 0;
  for(int i = 0;i<=Max;i++)
  {
    ans += dfs(len-1,sum+i*(len-point),point,flag&&i==Max);
  }
  if(!flag) dp[len][point][sum] = ans;
  return ans;

}
ll slove(ll x)
{
  int co = 1;
  if(x<0) return 0;
  while(x)
  {
    shu[co++] = x%10;
    x/=10;
  }
  ll ans = 0;
 for(int i = 1;i<co;i++)
 {
   ans +=dfs(co-1,0,i,1);
 }
 return ans-co+2;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  clr(dp,-1);
  while(t--)
  {
    ll a,b;
    cin>>a>>b;
    cout<<slove(b)-slove(a-1)<<endl;
  }
  return 0;
}
