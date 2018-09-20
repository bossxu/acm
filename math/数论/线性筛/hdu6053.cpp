#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
ll shu[100005];
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
const int N = 2e5+5;
int tree[N];
ll big;
int lowbit(int t)
{
  return t&(-t);
}
void add(int x,int y)
{
  for(int i=x;i<=N;i+=lowbit(i))
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
<<<<<<< HEAD
ll cal(int big,int k)
{
  ll op = 1;
  for(int i = k,l = 1;i<=big;i+=k,l++)
  {
    op = op*quick(l,(getsum(i+k-1)-getsum(i)));
=======
ll cal(int k)
{
  ll op = 1;
  for(int i = k;i<=big;i+=k)
  {
    op = (op*quick(i/k,getsum(i+k-1)-getsum(i-1)))%mod;
>>>>>>> a4777e3c2a1667a08f388e12a2ae998bb55e0b7c
  }
  return op;
}
int main()
{
  int t;
  scanf("%d",&t);
  int tot = 0;
  int n;
  Moblus();
  while(t--)
  {
      scanf("%d",&n);
      clr(tree,0);
      ll minn = 1000005;
      big = 0;
      for(int i = 1;i<=n;i++)
      {
        scanf("%lld",&shu[i]);
        add(shu[i],1);
        minn = min(minn,shu[i]);
        big = max(big,shu[i]);
      }
      ll ans = 0;
      for(int i = 2;i<=minn;i++)
      {
<<<<<<< HEAD
        ans = (ans+mu[i]*cal(shu[1],i))%mod;
=======
        if(mu[i] == 0) continue;
        ans = (ans+mu[i]*cal(i))%mod;
>>>>>>> a4777e3c2a1667a08f388e12a2ae998bb55e0b7c
      }
      ans*=-1;
      (ans += mod)%=mod;
      printf("Case #%d: %lld\n",++tot,ans);
  }
  return 0;
}
