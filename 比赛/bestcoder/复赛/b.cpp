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
const int N = 10005;
ll l[N],r[N];
ll sum[N];
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
ll inv = (mod+1)/2;
ll w[105];
ll suan(int n,int m)
{
    return (1LL*(n+m)*(m-n+1)%mod)*inv%mod;
}
int main()
{
  ios_close;
  int t;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
      cin>>l[i]>>r[i];
    }
    ll down = l[1],up = r[1];
    for(int i = 2;i<=n;i++)
    {
      down = max(down,l[i]);
      up = max(up,r[i]);
    }
    ll ans = 0;
    for(int i = down;i<=up;i++)
    {
      ll tmp = 1;
      w[n+1] = 1;
      for(int j = 1;j<=n;j++)
      {
        int x = max(2*1LL,i-r[j]+1);
        int y = i - l[j]+1;
        w[j] = suan(x,y);
      }
      for(int j =n;j>=1;j--)
      {
        w[j] = w[j]*w[j+1]%mod;
      }
      for(int j = 1;j<=n;j++)
      {
        if(r[j]>=i) ans = (ans + tmp * w[j+1])%mod;
        int x = max(1LL,i-r[j]+1);
        int y = i-l[j]+1;
        tmp = tmp*suan(x,y)%mod;
      }
    }
    ll fenmu = 1;
    for(int i = 1;i<=n;i++)
    {
      fenmu = fenmu*(r[i]-l[i]+1)%mod;
    }
    cout<<ans*quick(fenmu,mod-2)%mod<<endl;
  }
  return 0;
}
