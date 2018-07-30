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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int dp[11][11];
int vis[11][11];
ll C[10][30005];
void init()
{
  C[0][0] = C[1][1] = C[2][2] = C[3][3] = C[4][4] = C[5][5] = 1;
  for(int i = 1;i<=3000;i++)
  {
    C[0][i] = 1;
    for(int j = 1;j<=8;j++)
    {
      C[j][i] = (C[j-1][i-1] + C[j][i-1])%mod;
    }
  }
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  clr(C,0);
  init();
  while(t--)
  {
    int n,m;
    clr(dp,0);
    cin>>n>>m;
    while(m--)
    {
      char s;
      int v,u;
      cin>>s>>u>>v;
      int flag = s =='+'?1:-1;
      vis[u][v]+=flag;
      for(int j = 1;j<=n;j++)
      {
        for(int k = j+1;k<=n;k++)
        {
          if(j==u || k==v)
          {
            continue;
          }
          dp[j][k]+=flag;
        }
      }
      int sum = 0;
      for(int j = 1;j<=n;j++)
      {
        for(int k = j+1;k<=n;k++)
        {
          if(vis[j][k])
          {
            sum += vis[j][k];
          }
        }
      }
      cout<<sum;
      for(int i = 2;i<=n/2;i++)
      {
        sum = 0;
        for(int j = 1;j<=n;j++)
        {
          for(int k = j+1;k<=n;k++)
          {
            if(vis[j][k] > 0)
            {
              sum += C[i-1][dp[j][k]];
            }
          }
        }
        cout<<" "<<sum/2;
      }
      cout<<endl;
    }
  }
  return 0;
}
