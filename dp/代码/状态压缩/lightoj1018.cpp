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
const double eps = 1e-6;
struct Node{
  int x,y;
}node[17];
int line[20][20];
int n;
int dp[1<<16];
bool check(int i,int j,int z)
{
   int x = node[i].x - node[j].x;
   int y = node[i].y - node[j].y;
   if(x * (node[z].y-node[i].y) == y * (node[z].x-node[i].x))
   return 1;
   return 0;

}
int getnum(int x)//用来得到数位上1的个数
{
  int ret = 0;
   while(x)
   {
       x &= x-1;
       ++ret;
   }
   return ret;
}
int dfs(int s)
{
  if(dp[s] < INF) return dp[s];
  int ret = INF;
  if(s == 0) return 0;
  int num = getnum(s);
  if(num<=2) return 1;
  int i =0;
  while(!(s&(1<<i)) )  i++;
  for(int j= i+1;j<n;j++)
  {
    if(s & (1<<j))
    {
      ret = min(ret , dfs(s&(~line[i][j])) + 1 );
    }
  }
  dp[s] = ret;
  return ret;
}
void init()
{
  clr(dp,INF);
  dp[0] = 0;
  for(int i = 0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      line[i][j] = (1<<i) | (1<<j);
      for(int k =j+1;k<n;k++)
      {
        if(check(i,j,k))
        line[i][j] |= (1<<k);
      }
      line[j][i] = line[i][j];
    }
  }
}
int main()
{
  /*freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);*/
  int t,co=0;
  cin>>t;
  while(t--)
  {
    cin>>n;
    clr(line,0);
    for(int i = 0;i<n;i++)
    {
      scanf("%d%d",&node[i].x,&node[i].y);
    }
    init();
    printf("Case %d: %d\n",++co,dfs((1<<n)-1));
  }
  return 0;
}
