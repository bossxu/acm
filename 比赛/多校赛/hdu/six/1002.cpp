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
const int MAXN = 1000005;
bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];
void Moblus()
{
    clr(check,0);
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= MAXN; i++)
    {
        if( !check[i] )
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

ll quick(ll a, ll b)
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
ll dp[2000005];
ll f[1000005];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=2000000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
  f[0] = 0;
  f[1] = 1;
  for(int i = 2;i<=1000000;i++)
  {
    f[i] = (f[i-2] + f[i-1] )%(mod-1);
  }
}
ll C(int n,int k)
{
  ll ans = dp[n];
  ans = ans*quick(dp[n-k]*dp[k]%mod,mod-2)%mod;
}
vector<int>q;
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  ios_close;
  int t;
  init();
  Moblus();
  cin>>t;
  while(t--)
  {
    q.clear();
    ll n,k;
    cin>>n>>k;
    for(int i = 2;i*i<=n;i++)
    {
      if(n%i == 0)
      {
        q.pb(i);
        if(i*i!=n) q.pb(n/i);
      }
    }
    q.pb(n);
    int len = q.size();
    ll sum = 0;
    for(int i = 0;i<len;i++)
    {
      //cout<<q[i]<<endl;
      int num = n/q[i];
      ll a = 0;
      for(int i = 1;i<=num;i++)
      {
        if(num%i != 0) continue;
        a = (a+mu[i]*C(k+num/i-1,k-1))%mod;
      }
      ll flag = f[q[i]];
      sum = (sum+a*(quick(2,flag)-2)%mod)%mod;
    }
    sum%=mod;
    sum = sum*quick(C(n+k-1,k-1),mod-2)%mod;
    cout<<(sum+mod+1)%mod<<endl;
  }
  return 0;
}
