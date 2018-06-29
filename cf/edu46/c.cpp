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
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
struct Node
{
  ll x,st;
}node[400005];
int cmp(Node a, Node b)
{
  if(a.x == b.x) return a.st<b.st;
  return a.x<b.x;
}
ll ans[200005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  int tot = 1;
  for(int i = 1;i<=n;i++)
  {
    ll a,b;
    cin>>a>>b;
    node[tot].x = a;node[tot++].st = -1;
    node[tot].x = b;node[tot++].st = 1;
  }
  sort(node+1,node+tot,cmp);
  ll pre = -1,now = 0;

  for(int i = 1;i<tot;i++)
  {
    if(node[i].st == -1)
    {
      if(~pre) ans[now] += node[i].x - pre;
      pre = node[i].x;
      now++;
    }
    else
    {
      if(pre<=node[i].x) ans[now] +=node[i].x-pre+1;
      pre = node[i].x+1;
      now--;
    }
  }
  for(int i = 1;i<=n;i++) cout<<ans[i]<<" ";
  return 0;
}
