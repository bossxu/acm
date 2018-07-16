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
struct Node
{
  int t;
  int p;
  int index;
}node[100005];
int cmp(Node a, Node b)
{
  if(a.t == b.t)
  {
    return a.p<b.p;
  }
  return a.t>b.t;
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    for(int i = 1 ;i<=n;i++)
    {
      node[i].t = node[i].p = 0;
      node[i].index = i;
    }
    int st,ok;
    for(int i = 1;i<=m;i++)
    {
      cin>>st>>ok;
      node[st].t++;
      node[st].p+=ok;
    }
    sort(node+1,node+n+1,cmp);
    for(int i = 1;i<=n;i++)
    {
      cout<<node[i].index<<endl;
    }
  }
  return 0;
}
