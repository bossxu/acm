#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 998244353;
const double eps = 1e-6;
int lowbit(int t) {return t&(-t);}
int n;
struct Node{
  int p,d;
  int id;
}Q[100005];
ll tree[100005];
ll inv;
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    a = a*a%mod;
    b>>=1;
  }
  return res;
}
void add(ll x,ll y)
{
  for(int i = x;i<=n;i+=lowbit(i))
  {
    tree[i]=tree[i]*y%mod;
  }
}
ll getsum(int x)
{
  ll ans = 1;
  for(int i = x;i>0;i-=lowbit(i))
    ans=ans*tree[i]%mod;
  return ans%mod;
}
int cmp(Node a, Node b)
{
  if(a.d == b.d)
  {
    return a.id<b.id;
  }
  return a.d>b.d;
}
int ba(Node a,Node b)
{
  return a.id<b.id;
}
ll ans[100005];
int main()
{
  while(cin>>n)
  {
    inv = quick(100,mod-2);
    clr(tree,1);
    for(int i = 1;i<=n;i++)
    {
      cin>>Q[i].p>>Q[i].d;
      Q[i].id = i;
    }
    sort(Q+1,Q+n+1,cmp);
    for(int i = 1;i<=n;i++)
    {
      Q[i].d = i;
    }
    sort(Q+1,Q+n+1,ba);
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      ll a = getsum(Q[i].d-1);
      cout<<a<<endl;
      ans += (Q[i].p*a%mod)*inv%mod;
      //cout<<a<<" "<<sum<<endl;
      add(Q[i].d,(100-Q[i].p)*inv%mod);
    }
    cout<<ans<<endl;
  }
  return 0;
}
