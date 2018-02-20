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
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int vis[10];
void dfs(ll k)
{
  bool flag = 0;
  for(int i = 1;i<=8;i++)
  {
    if(!vis[i])
    {
      flag = 1;
      vis[i] = 1;
      dfs(k*10+i);
      vis[i] = 0;
    }
  }
  ll p = k;
  int o[10];
  if(!flag)
{
  for(int i =1;i<=8;i++)
  {
    o[i] = p%10;
    p/=10;
  }
  for(int i = 8;i>1;i--)
  cout<<o[i]<<" ";
  cout<<o[1]<<endl;
}
}
int main()
{
   clr(vis,0);
   //freopen("out.txt","w",stdout);
   for(int i = 1;i<=8;i++)
   {
     vis[i] = 1;
     dfs(i);
     vis[i] = 0;
   }
  return 0;
}
