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
char s[1005];
char t[1005];
int dp[2005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m,q;
  while(cin>>n>>m>>q)
  {
    cin>>s+1>>t+1;
    clr(dp,0);
    for(int i = 1;i<=n;i++)
    {
      //cout<<s[i]<<endl;
      if(s[i] != t[1])
      {
        continue;
      }
      int flag = 1;
      for(int j = 1;j<m && j+i<=n;j++)
      {
        if(s[i+j]!=t[j+1])
        {
          flag = 0;
          break;
        }
      }
      if(flag)
      {
        dp[i] = i+m-1;
      }
    }
    for(int i = 1;i<=q;i++)
    {
      int l,r;
      cin>>l>>r;
      ll ans = 0;
      for(int i = l;i<=r;i++)
      {
        if(dp[i]!=0 && dp[i]<=r)
        {
          ans++;
        }
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}
