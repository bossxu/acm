#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
vector<int>quan[20005];
ll a[20005];
ll que[20005];
ll sum[20005];
int vis[20005];
ll n,m,s,k;
ll solve(vector<int>op,int len)
{
  ll ans = 0;
  ll len = op.size();
  for(int i = 1;i<=len;i++) pre
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t;
  scanf("%d",&t);
  int kase=0;
  while(t--)
  {
    clr(vis,0);
    scanf("%lld%lld%lld%lld",&n,&s,&m,&k);
    for(int i=0;i<=n;i++)
    {
      quan[i].clear();
    }
    for(int i = 0;i<n;i++)
    {
      scanf("%lld",&a[i]);
      a[i+n]=a[i];
    }
    int tot=0;
    ll tmp;
    for(int i = 0;i<n;i++)
    {
      int next = i;
      if(!vis[next])
        tot++;
      while(!vis[next])
      {
        vis[next] = 1;
        quan[tot].pb(next);
        next = (next+k)%n;
      }
    }

    printf("Case #%d: %lld\n",++kase,max(0LL,S-fx));
  }
  return 0;
}
