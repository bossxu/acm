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
ll shu[100005];
int main()
{
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    ll n,m;
    cin>>n>>m;
    //cout<<n*m<<endl;
    shu[0] = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      shu[i]+=shu[i-1];
    }
    ll inv = quick(2LL,n*m);
    while(m--)
    {
      int a,b,c;
      cin>>a>>b>>c;
      if(a == 2)
      {
        cout<<(((shu[c]-shu[b-1])%mod)*inv%mod+mod)%mod<<endl;
      }
    }
  }
  return 0;
}
