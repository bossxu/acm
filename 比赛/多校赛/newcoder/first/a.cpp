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
ll C[1005][1005];
void init()
{
C[0][0] = 1;
C[1][0] = C[1][1] = 1;
for(int i = 2; i <= 1000; i++) {
C[i][0] = 1;
for(int j = 1; j <= i; j++)
C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
}
}
int n,m;
int ans = 0;
int map[20][20];
bool check()
{
  for(int i =1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      if(map[i][j]<map[i-1][j] || map[i][j]<map[i][j-1])
      return 0;
    }
  }
  return 1;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  init();
  for(int i = 1;i<=12;i++)
  {
    for(int j = 1;j<=i;j++)
    {
      printf("(%d,%d) = %lld  ",i,j,C[i][j]);
    }
    cout<<endl;
  }
  while(cin>>n>>m)
  {
    ans = 0;
    clr(map,0);
    for(int i = 0;i<pow(3,n*m);i++)
    {
      int op = i;
      for(int j = 1;j<=n;j++)
      {
        for(int k = 1;k<=m;k++)
        {
          map[j][k] = op%3;
          op/=3;
        }
      }
      if(check())
      ans++;
    }
    cout<<ans<<endl;
    for(int i = 2;i*i<=ans;i++)
    {
      if(ans%i == 0)
      {
        printf("  (%d %d) ",i,ans/i);
      }
    }
    cout<<endl;
  }
  return 0;
}
