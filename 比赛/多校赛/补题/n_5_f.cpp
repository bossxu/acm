#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 998244353;
const double eps = 1e-6;
const int N = 1e5+5;
//也是学的不够精，这里转换的点在于把这些东西都变成每个点所给的贡献，因为独立，所以就转换成了
//求和的期望和求期望的和的问题，去求每个点贡献的期望，还是学的不够精，这个没有想到
//不过像这类题目，也差不多找到规律了，就是算状态点的期望。
struct node
{
  int id;
  int p;
  ll d;
}Q[N];
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
int cmp(node a,node b)
{
  if(a.d == b.d)
  {
    return a.id<b.id;
  }
  return a.d>b.d;
}
int cmp_id(node a,node b)
{
  return a.id < b.id;
}
int n;
ll tree[N];
int lowbit(int t) {return t&(-t);}
void add(int x ,ll y)
{
  for(int i = x;i<=n;i+=lowbit(i))
  {
    tree[i] = y*tree[i]%mod;
  }
}
ll getmul(int x)
{
  ll ans = 1;
  for(int i = x;i>0;i-=lowbit(i))
  {
    ans=ans*tree[i]%mod;
  }
  return ans;
}
int main()
{
  ios_close;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>Q[i].p>>Q[i].d;
      Q[i].id = i;
      tree[i] = 1;
    }
    tree[0] = 1;
    sort(Q+1,Q+n+1,cmp);
    for(int i = 1;i<=n;i++)
    {
      Q[i].d = i;
    }
    sort(Q+1,Q+n+1,cmp_id);
    ll inv = quick(100,mod-2);
    ll ans = 0;
    //cout<<"hello"<<endl;
    for(int i = 1;i<=n;i++)
    {
      //cout<<getmul(Q[i].d-1)<<endl;
      ll temp = (getmul(Q[i].d-1)*(Q[i].p)%mod)*inv%mod;
      ans += temp;
      add(Q[i].d,(100-Q[i].p)*inv%mod);
    }
    cout<<ans%mod<<endl;
  }
  return 0;
}
