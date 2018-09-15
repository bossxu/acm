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
int shu[100005];
const int MAXN = 100005;
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
ll cal(int n,int k)
{
  ll op = 1;
  for(int i = 1;i<=n;i++)
  {
    op = (shu[i]/k)*op%mod;
    if(!op) break;
  }
  return op;
}
int main()
{
    //ios_close;
    int t;
    int tot = 0;
    Moblus();
    scanf("%d",&t);
    while(t--)
    {
      int n;
      scanf("%d",&n);
      for(int i = 1;i<=n;i++)
      {
        scanf("%d",&shu[i]);
      }
      sort(shu+1,shu+n+1);
      ll ans = 0;
      for(int i = 2                                                                                                                                                                                                        ;i<=shu[n];i++)
      {
        ans = (ans + mu[i]*cal(n,i))%mod;
      }
      ans = ans*(-1);
      (ans += mod)%=mod;
      printf("Case #%d: %lld\n",++tot,ans);
    }
    return 0;
}
