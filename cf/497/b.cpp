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
vector<int>op[3];
ll dp[100005][3];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    ll shu[3];
    clr(dp,0);
    for(int i = 0;i<3;i++) op[i].clear();
    cin>>shu[0]>>shu[1]>>shu[2];
      sort(shu,shu+3);
      ll a,b,c;
      a = shu[0],b = shu[1],c = shu[2];
      for(int i = 1;i*i<=a;i++)
      {
        if(a%i == 0)
        {
          if(i*i == a)
          {
            op[0].push_back(i);
          }
          else
          {
            op[0].push_back(i);
            op[0].push_back(a/i);
          }
        }
      }
      for(int i = 1;i*i<=b;i++)
      {
        if(b%i == 0)
        {
          if(i*i == b)
          {
            op[1].push_back(i);
          }
          else
          {
            op[1].push_back(i);
            op[1].push_back(b/i);
          }
        }
      }
      for(int i = 1;i*i<=c;i++)
      {
        if(c%i == 0)
        {
          if(i*i == c)
          {
            op[2].push_back(i);
          }
          else
          {
            op[2].push_back(i);
            op[2].push_back(c/i);
          }
        }
      }
      for(int i = 0;i<3;i++) sort(op[i].begin(),op[i].end());
      int len1 = op[1].size();
      int len2 = op[2].size();
      for(int i = 0;i<len1;i++)
      {
        int k = lower_bound(op[0].begin(),op[0].end(),op[1][i]) - op[0].begin();
        if(op[0][k] == op[1][i])
        {
          dp[i][1] = k+1;
        }
        else
        dp[i][1] = k;
      }
      for(int i = 1;i<len1;i++)
      {
        dp[i][1]+=dp[i-1][1];
      }
      for(int i = 0;i<len2;i++)
      {
        int k = lower_bound(op[1].begin(),op[1].end(),op[2][i]) - op[1].begin();
        if(op[1][k] == op[2][i])
        {
          dp[i][2] = dp[k][1];
        }
        else
        dp[i][2] = dp[k-1][1];
      }
      ll ans = 0;
      for(int i = 0;i<len2;i++)
      {
        ans+=dp[i][2];
      }
      cout<<ans<<endl;
    }
  return 0;
}
