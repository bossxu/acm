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
#define clr(a,x) memset(a,x,sizeof(a))
//带权并查集
//通过记录到底点的距离；来做带权并查集
int pre[200005];
int shu[200005];
int ans;
int find(int x)
{
  if(x == pre[x])
  {
    return x;
  }
  int t = pre[x];
  pre[x] = find(pre[x]);
  shu[x]+=shu[t];
  return pre[x];
}
void Union(int a,int b,int s)
{
  int x = find(a);
  int y = find(b);
  if(x == y)
  {
    if(shu[a]+s!=shu[b])
    {
      ans++;
    }
    return;
  }
  else
  {
    pre[y] = x;
    shu[y] = shu[a]+s-shu[b];
  }
}
int n,m;
void init()
{
    for(int i = 0;i<=n;i++)
    {
      pre[i] = i;
    }
    clr(shu,0);
}
int main()
{
  std::ios::sync_with_stdio(false);
  while(cin>>n>>m)
  {
    init();
    int a,b,s;
    ans = 0;
    while(m--)
    {
      cin>>a>>b>>s;
      Union(a,b+1,s);
    }
    cout<<ans<<endl;
  }
  return 0;
}
