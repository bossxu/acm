#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int mod,n,m;
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
ll phi[MAXN];
ll inv[MAXN];
ll dp[MAXN];
int maxn = MAXN;
void init()
{
  for(int i = 1;i<=maxn;i++) phi[i] = i;
  for(int i = 2;i<=maxn;i+=2) phi[i]/=2;
  for(int i = 3;i<=maxn;i+=2)
  {
    if(phi[i] == i)
    {
      for(int j = i;j<=maxn;j+=i)
      {
        phi[j] = phi[j]/i*(i-1);
      }
    }
  }
}
void dell()
{
  inv[1]=1;
  for(int i=2;i<=n;i++)
      inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  for(int i = 1;i<=n;i++)
  {
    dp[i] = inv[i]*phi[i]%mod;
  }
}
ll slove(int n,int m)
{
  ll res = 0;
  int len = min(n,m);
  for(int i = 1;i<=len;i++)
  {
    res += mu[i]*(n/i)*(m/i);
  }
  return res%mod;
}
int main()
{
  ios_close;
  Moblus();
  init();
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>m>>mod;
    dell();
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      ans += dp[i]*slove(n/i,m/i);
    }
    cout<<ans%mod<<endl;
  }
  return 0;
}
