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
int shu[100005];
int dp[276];
int main()
{
  int n,k;
  while(cin>>n>>k)
  {
    for(int i = 1;i<=256;i++)
    dp[i] = -1;
    for(int i = 1;i<=n;i++)
    {
      scanf("%d",&shu[i]);
    }
    for(int i = max(0,shu[1]-k+1);i<shu[1];i++)
    {
      dp[shu[1]] = max(shu[1]-k+1,0);
    }
    shu[1] = max(shu[1]-k+1,0);
    cout<<shu[1];
    for(int i = 2;i<=n;i++)
    {
      int l = shu[i];
      int j;
      for(j = i;j>=0 && j>=l-k+1;j--)
      {
        cout<<"-"<<j<<endl;
        if(dp[j]!=-1)
        {
          break;
        }
      }
      int o = j;
      for(;j<=l;j++)
      {
        dp[j] = o;
      }
      cout<<" "<<dp[l];
    }
    cout<<endl;

  }
    return 0;
}
