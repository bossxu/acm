#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
<<<<<<< HEAD
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
int shu[100005];
=======
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
ll shu[100005];
>>>>>>> 00eea5a17a948c38f3b0702aea20bcd87a081730
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
<<<<<<< HEAD
ll cal(int n,int k)
{
  ll op = 1;
  for(int i = 1;i<=n;i++)
  {
    op = (shu[i]/k)*op%mod;
    if(!op) break;
=======
const int N = 1e5+5;
int tree[N];
int n;
int lowbit(int t)
{
  return t&(-t);
}
void add(int x,int y)
{
  for(int i=x;i<=n;i+=lowbit(i))
  tree[i]+=y;
}
int getsum(int x)
{
  int ans=0;
  for(int i=x;i>0;i-=lowbit(i))
    ans+=tree[i];
  return ans;
}
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
ll cal(int n,int k)
{
  ll op = 1;
  for(int i = k;i<=n;i+=k)
  {
    op = op*quick(i,(getsum(i)-getsum(i-k))*(i/k-1));
>>>>>>> 00eea5a17a948c38f3b0702aea20bcd87a081730
  }
  return op;
}
int main()
{
<<<<<<< HEAD
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
=======
  int t;
  scanf("%d",&t);
  int tot = 0;
  Moblus();
  while(t--)
  {
      cin>>n;
      for(int i = 1;i<=n;i++)
      {
        scanf("%lld",&shu[i]);
        add(shu[i],1);
      }
      ll ans = 0;
      for(int i = 2;i<=shu[1];i++)
      {
        ans = (ans+mu[i]*cal(n,i))%mod;
      }
      ans*=-1;
      printf("Case #%d: %lld\n",++tot,ans);
  }
  return 0;
>>>>>>> 00eea5a17a948c38f3b0702aea20bcd87a081730
}
