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
struct node
{
  ll val;
  int vis;
  bool operator <(const node& A) const
  {
    if(val == A.val) return vis>A.vis;
    return val>A.val;
  }
}Q[100005];
priority_queue<node,vector<node>,less<node> >q;
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    while(!q.empty()) q.pop();
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
      scanf("%lld",&Q[i].val);
      Q[i].vis = 1;
    }
    ll ans = 0;
    int cnt = 0;
    for(int i = 1;i<=n;i++)
    {
      if(!q.empty() && q.top().val<Q[i].val)
      {
        node p = q.top();
        q.pop();
        ans += Q[i].val-p.val;
        cnt += p.vis*2;
        q.push(Q[i]);
        p.val = Q[i].val;
        p.vis = 0;
        q.push(p);
      }
      else
      q.push(Q[i]);
    }
    printf("%lld %d\n",ans,cnt);
  }
  return 0;
}
