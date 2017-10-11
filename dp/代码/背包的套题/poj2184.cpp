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
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
//0 1 背包的变形
// 同时取最大的时候， 我就把一个看作容量一个看做价值来解决
// 这题就是在 重量为负的时候的处理方案;
// 核心的思想在于01背包的问题怎么处理，是从后到前还是从后到前;
// 因为我这个必须要有前置才能这样处理;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int dp[200005];
  int happy[105],smart[105];
  int n;
  while(cin>>n)
  {
    for(int i=1;i<=n;i++)
    cin>>happy[i]>>smart[i];
    clr(dp,-INF);
    dp[100000]=0;
    for(int i =1;i<=n;i++)
    {
      if(happy[i]<0 && smart[i]<0)
      {
        continue;
      }
      if(happy[i]>0)
      {
        for(int j=200000;j>=happy[i];j--)
        {
          if(dp[j-happy[i]]>-INF)
          dp[j]=max(dp[j],dp[j-happy[i]]+smart[i]);
        }
      }
      else
        for(int j=0;j<=200000+happy[i];j++)
        {
          if(dp[j-happy[i]]>-INF)
          dp[j]=max(dp[j-happy[i]]+smart[i],dp[j]);
        }

    }
    int ans =  0 ;
    for(int i=100000;i<=200000;i++)
    {
      //cout<<dp[i]<<endl;
      if(dp[i]>0)
            ans=max(ans,dp[i]+i-100000);
    }
    cout<<ans<<endl;
  }
  return 0;
}
