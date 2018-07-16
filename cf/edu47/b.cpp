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
char s[100005];
int m[100005];
int dp[3];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  while(cin>>s)
  {
    int len = sizeof(s);
    int tot = 0;
    clr(dp,0);
    for(int i = len-1;i>=0;i--)
    {
      if(s[i] == '2')
      {
        for(int j = 1;j<=dp[0];j++)
        {
          m[tot++] = 0;
        }
        m[tot++] = 2;
        dp[0] = 0;
      }
      if(s[i] == '1')
      {
        dp[1]++;
      }
      if(s[i] == '0')
      {
        dp[0]++;
      }
    }
    for(int i = 1;i<=dp[1];i++)
    {
      m[tot++] = 1;
    }
    for(int i = 1;i<=dp[0];i++)
    {
      m[tot++] = 0;
    }
    clr(dp,0);
    for(int i = tot-1;i>=0;i--)
    {
      cout<<m[i];
    }
    cout<<endl;
  }
  return 0;
}
