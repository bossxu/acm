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
const int N = 1e5+5;;
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
int main()
{
  ios_close;
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>Q[i].p>>Q[i].d;
      Q[i].id = i;
    }
    sort(Q+1,Q+n+1,cmp);
  }
  return 0;
}
