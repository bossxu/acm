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
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
int shu[200005];
int dp[200005];
int ans[200005];
int main()
{
  int n,k;
  std::ios::sync_with_stdio(false);
  while(cin>>n>>k)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      dp[i] = shu[i];
    }
    sort(shu+1,shu+n+1);
    for(int i=1;i<=n;i++)
    {
        ans[i]=lower_bound(shu+1,shu+1+n,dp[i])-shu-1;
    }
    int a,b;
    for(int i = 1;i<=k;i++)
    {
      cin>>a>>b;
      if(dp[a]>dp[b])
        ans[a]--;
        else if(dp[a]<dp[b])
        ans[b]--;
    }
    for(int i = 1;i<n;i++)
    {
      cout<<ans[i]<<" ";
    }
    cout<<ans[n]<<endl;
  }
  return 0;
}
