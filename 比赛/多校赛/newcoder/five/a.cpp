#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
struct Node
{
  ll s,c;
}node[100005];

int cmp(Node a,Node b)
{
  if(a.c == b.c)
  {
    return a.s>b.s;
  }
  return a.c<b.c;
}

int main()
{
  int n,k;
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  while(scanf("%d%d",&n,&k) == 2)
  {
    for(int i = 1;i<=n;i++)
    {
      scanf("%lld",&node[i].s);
    }
    for(int i = 1;i<=n;i++)
    {
      scanf("%lld",&node[i].c);
    }
    sort(node+1,node+n+1,cmp);
    ll mu = 0,zi = 0;
    for(int i = k+1;i<=n;i++)
    {
      zi += node[i].c*node[i].s;
      mu += node[i].s;
    }
    double ans = zi/mu;
    //cout<<ans<<endl;
    ans += ((zi%mu)*1.0/mu);
    printf("%.7lf\n",ans);
  }
  return 0;
}
