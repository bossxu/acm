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
#define clr(a,x) memset(a,x,sizeof(a))
int shu[11];
ll ans = 0;
ll dp[30];
void dfs(int len,int k)
{
  int flag = 1;
  ll num = 0;
  for(int i = 0;i<=min(shu[0],1);i++)
  {
      ll o = dp[len-i];
      for(int j = 0;j<=9;j++)
      {
        if(j == 0) o/=dp[shu[j]-i];
        else
        o/=dp[shu[j]];
      }
      if(flag) num+=o;
      else num-=o;
      flag^=1;
  }
  //cout<<num<<" --- "<<len<<endl;
  ans+=num;
  for(int i = k;i<=9;i++)
  {
    if(shu[i]>1)
    {
      shu[i]-=1;
      dfs(len-1,i);
      shu[i]++;
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  ll n;
  dp[0] = 1;
  for(int i = 1;i<=20;i++)
  {
    dp[i] = dp[i-1]*i;
  }
  while(cin>>n)
  {
    ans = 0;
    clr(shu,0);
    int len = 0;
    while(n)
    {
      len++;
      shu[n%10]++;
      n/=10;
    }
    dfs(len,0);
    cout<<ans<<endl;
  }
  return 0;
}
