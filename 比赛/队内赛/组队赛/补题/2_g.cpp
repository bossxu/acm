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
struct Node
{
  int t,p;
  bool operator <(const Node &A)
  {
    if(A.t == t) return p<A.p;
    return t>A.t;
  }
}node[100005];
set<Node>sot;
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    for(int i = 1;i<=n;i++)
    {
      node[i].t = node[i].p = 0;
    }
    for(int i = 1;i<=m;i++)
    {
      int o,p;
      cin>>o>>p;
      if(o == 1)
      {
        node[o].t+=1;
        node[o].p+=p;
      }
      else
      {
        if(node[o]<node[1])
        {
          sot.erase(sot.find(node[o]));
        }
        node[o].t+=1;
        node[o].p+=p;
        sot.
      }
    }
  }
  return 0;
}
