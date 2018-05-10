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
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
struct Node
{
  int a,b;
  int pre;
  int length;
}node[200005];
int cmp(Node z,Node p)
{
  if(z.a == p.a) return z.b<p.b;
  return z.a<p.a;
}
int cmp1(Node z, Node p)
{
  return z.a<p.a-1;
}
vector<int>ans;
vector<Node>zhong;
int vis[200005];
void pri(int i)
{
  if(i == -1) return;
  pri(node[i].pre);
  if(node[i].pre == -1)
  cout<<node[i].b;
  else
  cout<<" "<<node[i].b;


}
int main()
{
  int n;
  while(cin>>n)
  {
    clr(vis,0);
    for(int i = 1;i<=n;i++)
    {
      scanf("%d",&node[i].a);
      node[i].b = i;
      node[i].length = 1;
      node[i].pre = -1;
    }
    sort(node+1,node+n+1,cmp);
    int length = 0;
    int item = 0;
    for(int i = 1;i<=n;i++)
    {
      int z = lower_bound(node+1,node+i,node[i],cmp1) - node;
      if(node[z].a == node[i].a-1 && node[z].b < node[i].b)
      {
        node[i].length = node[z].length+1;
        node[i].pre = z;
      }
    }
    int st = 1;
    for(int i = 1;i<=n;i++)
    {
      if(node[i].length > node[st].length) st = i;
    }
    cout<<node[st].length<<endl;
    pri(st);
    cout<<endl;
  }
  return 0;
}
