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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
ll dp[50][1<<10][15];
int k;
int shu[50];
int getnum(int x)
{
  int co = 0;
  while(x )
  {
    co++;
    x&=(x-1);
  }
  return co;
}
int getnews(int x ,int st)
{
  for(int i=x;i<10;i++)
        if(st&(1<<i))return (st^(1<<i))|(1<<x);
    return st|(1<<x);
}
ll dfs(int len,int st,int pre,int flag)
{
  if(len < 0) return k == getnum(st);
  if(!flag && dp[len][st][k]!=-1) return dp[len][st][k];
  int Max = flag?shu[len]:9;
  ll ans = 0 ;
  for(int i=0;i<=Max;i++)
  {
    ans += dfs(len-1,(pre&&i==0)?0:getnews(i,st),pre && i==0,flag && i==Max);
  }
  if(!flag) dp[len][st][k] = ans;
  return ans;
}
ll slove(ll a)
{
  int co = 0;
  while(a)
  {
    shu[co++] = a%10;
    a/=10;
  }
  return dfs(co-1,0,1,1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    int co = 0;
    clr(dp,-1);
    while(t--)
    {
      ll a,b;
      cin>>a>>b>>k;
      printf("Case #%d: %lld\n",++co,slove(b)-slove(a-1));
    }

    return 0;
}
