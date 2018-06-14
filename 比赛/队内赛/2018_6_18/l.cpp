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
  int l,r;
}node[200005];
int cmp(Node a, Node b)
{
  if(a.l == b.l)
  {
    return a.r<b.r;
  }
  return a.l<b.l;

}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  //std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
      scanf("%d%d",&node[i].l,&node[i].r);
    }
    sort(node+1,node+n+1,cmp);
    int ans = 0;
    Node biao = node[1];
    for(int i = 2;i<=n;i++)
    {
      if(biao.r<node[i].l)
      {
        ans++;
        biao = node[i];
      }
      else
      {
        biao.l = max(node[i].l,biao.l);
        biao.r = min(node[i].r,biao.r);
      }
    }
    ans++;
    cout<<ans<<endl;
  }

  return 0;
}
