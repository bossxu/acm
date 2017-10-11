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
//二维背包
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int dp[105][105];
  int n,m,s,k;
  while(cin>>n>>m>>k>>s)
  {
    int ex[105],nai[105];
    for(int i=1;i<=k;i++)
    {
      cin>>ex[i]>>nai[i];
    }
    clr(dp,0);
    for(int i=1;i<=k;i++)
    {
      for(int j=0;j<=m;j++)
      {
        for(int l=1;l<=s;l++)
          if(j>=nai[i])
           dp[l][j]=max(dp[l][j],dp[l-1][j-nai[i]]+ex[i]);
      }
    }
    int i=m;
    while( dp[s][i-1]>= n)
    {
      i--;
    }
      if(dp[s][i]>=n)
      cout<<m-i<<endl;
      else
      cout<<"-1"<<endl;
  }

    return 0;
}
