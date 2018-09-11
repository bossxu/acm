#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll __int128
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll mod = 1e9+7;
ll inv6 ;
ll cal_f(ll n)
{
  return n*(n+1)%mod*(2*n+1)*2%mod%mod;
}
ll cal_s(ll n)
{
  ll st = n*(n+1)%mod;
  return st*st*3%mod;
}
const int MAXN = 200005;
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
ll Cal(ll n)
{
  ll ans = 0;
  for(ll i = 2;i*i<=n;i++)
  {
    ll up = i*i%mod;
    ans = (ans + mu[i]*((up*up%mod*cal_f(n/i/i))%mod*(n+1)%mod - up*up%mod*up%mod*cal_s(n/i/i)%mod));
  }
  return ans;
}
int main()
{
  long long l,k;
  Moblus();
  ll n;
  while(cin>>l>>k)
  {
    k*=12;
    n = l;
    mod = k;
    ll all = (n+1)%mod*cal_f(n) - cal_s(n);
    (all += mod)%=mod;
    all += Cal(n);
    all %= mod;
    all = (all+mod)%mod;
    all = all/12;
    long long ans = all;
    cout<<ans<<endl;
  }

  return 0;
}
