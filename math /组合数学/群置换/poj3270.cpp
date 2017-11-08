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
struct node{
  int val;
  int num;
};
int n;
node shu[10005];
int vis[10005];
int m[10005];
int t[10005];
int tot,minn;
void dfs(int x)
{
  for(int i = 1;i<=n;i++)
  {
    if(t[i] == x && !vis[i])
    {
      vis[i] = true;
      shu[tot].num++;
      shu[tot].val = min(shu[tot].val,t[i]);
      dfs(m[i]);
    }
  }
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  while(cin>>n)
  {
    clr(vis,0);
    int sum = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>m[i];
      t[i] = m[i];
      sum+=m[i];
    }
   sort(m+1,m+1+n);
   minn = min(m[1],m[n]);
   tot = 0;
   for(int i = 1;i<=n;i++)
   {
      if(vis[i]) continue;
      shu[tot].val = t[i];
      shu[tot].num = 1;
      vis[i] = true;
      dfs(m[i]);
      tot++;
   }
  for(int i =0;i<tot;i++)
  {
    sum += min(shu[i].val*(shu[i].num-2),minn*(shu[i].num+1)+shu[i].val);
  }
  cout<<sum<<endl;

  }
  return 0;
}
