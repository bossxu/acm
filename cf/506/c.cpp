#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
struct node
{
  ll l, r;
  int id;
}Q[300005];
int cmp_l(node a, node b)
{
  if(a.l == b.l)
  {
    return a.id<b.id;
  }
  return a.l>b.l;
}
int cmp_r(node a,node b)
{
  if(a.r == b.r)
  {
    return a.id<b.id;
  }
  return a.r<b.r;
}
int cmp(node a,node b)
{
  return a.id<b.id;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>Q[i].l>>Q[i].r;
      Q[i].id = i;
    }
    int l1,l2,r1,r2;
    sort(Q+1,Q+n+1,cmp_l);
    l1 = Q[1].id,l2 = Q[2].id;
    sort(Q+1,Q+n+1,cmp_r);
    r1 = Q[1].id,r2 = Q[2].id;
    sort(Q+1,Q+n+1,cmp);
    ll ans = 0;
    if(l1 == r1)
    {
      ans = max(ans,Q[r2].r-Q[l2].l);
    }
    else
    {
      ans = max(ans,max(Q[r2].r-Q[l1].l , Q[r1].r - Q[l2].l));
    }
    cout<<ans<<endl;
  }
  return 0;
}
