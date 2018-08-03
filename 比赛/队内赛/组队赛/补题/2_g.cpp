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
//这是一道用set去维护一定东西的题
//但是怎么优化我要维护的东西不是很简单的事。
//set删除不存在的数会t
struct Node
{
  int t,p;
  int index;
  bool operator <(const Node A) const
  {
    if(A.t == t) return p<A.p;
    return t>A.t;
  }
}node[100005];
multiset<Node>sot;
int main()
{
  //std::ios::sync_with_stdio(false);
  //cin.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    for(int i = 1;i<=n;i++)
    {
      node[i].t = node[i].p = 0;
      node[i].index = i;
    }
    for(int i = 1;i<=m;i++)
    {
      int o,p;
      scanf("%d%d",&o,&p);
      if(o == 1)
      {
        node[o].t+=1;
        node[o].p+=p;
      }
      else
      {
        if(sot.find(node[o])!=sot.end())
          sot.erase(sot.find(node[o]));
        node[o].t+=1;
        node[o].p+=p;
        sot.insert(node[o]);
      }
      while(!sot.empty() && !(*--sot.end() < node[1]))
      {
        sot.erase(--sot.end());
      }
      printf("%d\n",sot.size()+1);
    }

  }
  return 0;
}
