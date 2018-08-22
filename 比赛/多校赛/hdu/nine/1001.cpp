#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const double eps = 1e-6;
ll dp[80][80][6405];
ll mod;
int main()
{
  ios_close;
  int t;
  cin>>t;
  int n,m;
  while(t--)
  {
    cin>>n>>m>>mod;
    //init();
    for(int i = 1;i<=n*m;i++)
    {
      dp[1][1][i] = 1;
    }
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        for(int k = i*j;k<=n*m;k++)
        {
          
        }
      }
    }
    cout<<dp[n][m][n*m]<<endl;
  }
  return 0;
}
