#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn = 505;
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    int dp[10005];
    int w[maxn],v[maxn];
    while(t--)
    {
      int n;
      int v1,v2;
      cin>>v1>>v2;
      int V = v2-v1;
      cin>>n;
      for(int i=1 ; i<=n;i++)
      {
        scanf("%d%d",&v[i],&w[i]);
      }
      clr(dp,INF);
      dp[0]=0;
      for(int i=1;i<=n;i++)
      {
        for(int j=0;j<=V;j++)
        {
          if(j>=w[i])
          {
            dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
          }
        }
      }
      if(dp[V]==INF)
        cout<<"This is impossible."<<endl;
      else
      cout<<"The minimum amount of money in the piggy-bank is "<<dp[V]<<'.'<<endl;
    }

    return 0;
}
