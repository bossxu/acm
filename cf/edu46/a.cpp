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
map<string,int>q;
int dp[3][30];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  q["M"] = 1;
  q["S"] = 2;
  q["XS"] = 3;
  q["XXS"] = 4;
  q["XXXS"] = 5;
  q["L"] = 6;
  q["XL"] = 7;
  q["XXL"] = 8;
  q["XXXL"] = 9;
  while(cin>>n)
  {
    clr(dp,0);
    for(int i = 0;i<n;i++)
    {
      char s[10];
      cin>>s;
      dp[1][q[s]]++;
    }
    for(int i = 0;i<n;i++)
    {
      char s[10];
      cin>>s;
      dp[2][q[s]]++;
    }
    int ans = n;
    for(int i = 1;i<=9;i++)
    {
      ans-=min(dp[1][i],dp[2][i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}
