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
const int N = 2e5;
int t,n;
struct node
{
  ll a,val;
  int id;
  int to;
}Q[N];
ll tree[N];
int lowbit(int t)
{
  return t&(-t);
}
void add(int x,ll y)
{
  for(int i=x;i<=n;i+=lowbit(i))
  tree[i]=max(y,tree[i]);
}
ll getsum(int x)
{
  ll ans=0;
  for(int i=x;i>0;i-=lowbit(i))
    ans = max(tree[i],ans);
  return ans;
}
int cmp(node u,node v)
{
  if(u.a == v.a)
  {
    return u.val > v.val;
  }
  else
  return u.a < v.a;
}
int cmp_id(node u,node v)
{
  return u.id < v.id;
}
int main()
{
  ios_close;
  cin>>t;
  while(t--)
  {
    clr(tree,0);
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
      cin>>Q[i].a;
      Q[i].id = i;
    }
    for(int i = 1;i<=n;i++)
    {
      cin>>Q[i].val;
    }
    sort(Q+1,Q+n+1,cmp);
    int tot = 1;
    for(int i = 1;i<=n;i++)
    {
      if(i == 1 || Q[i].a == Q[i-1].a) Q[i].to = tot;
      else Q[i].to = ++tot;
    }
    ll maxn = 0;
    sort(Q+1,Q+n+1,cmp_id);
    for(int i = 1;i<=n;i++)
    {
      //cout<<Q[i].to<<endl;
      ll ans = Q[i].val;
      ll ad = getsum(Q[i].to-1);
      maxn = max(ans+ad,maxn);
      add(Q[i].to,ans+ad);
    }
    cout<<maxn<<endl;
  }
  return 0;
}
