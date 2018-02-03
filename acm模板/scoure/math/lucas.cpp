//卢卡斯定理
//用于求组合数 当那两个玩意特别大的时候
//注意啊，我这里是用快速幂来求乘法逆元
//他的要求为 mod 必须为素数
//好像也没有如果，不然好像还真不知道
int mod;
ll dp[maxn+5];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=mod;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
ll quick(ll a , ll n)
{
  ll res = 1;
  while(n)
  {
     if(n&1) res = res*a%mod;
     a = (a%mod)*(a%mod)%mod;
     n/=2;
  }
  return res;
}
ll lucas(ll n, ll m)
{
  ll ret = 1;
  while(n && m)
  {
    ll a = n%mod, b = m%mod;
    if(a<b) return 0;
    ret = ((ret * dp[a])%mod*quick(dp[b]*dp[a-b]%mod,mod-2))%mod;
    n/=mod;
    m/=mod;
  }
  return ret;
}
//扩展卢卡斯定理 及p不为素数  p<=1000000左右吧
//还利用了中国剩余定理
ll n,m,MOD,ans;

ll fast_pow(ll a,ll p,ll Mod)
{
    ll ans=1ll;
    for (;p;p>>=1,a=a*a%Mod)
        if (p&1)
            ans=ans*a%Mod;
    return ans;
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
    if (!b) x=1ll,y=0ll;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
ll inv(ll A,ll Mod)
{
    if (!A) return 0ll;
    ll a=A,b=Mod,x=0ll,y=0ll;
    exgcd(a,b,x,y);
    x=((x%b)+b)%b;
    if (!x) x+=b;
    return x;
}
ll Mul(ll n,ll pi,ll pk)
{
    if (!n) return 1ll;
    ll ans=1ll;
    if (n/pk)
    {
        for (ll i=2;i<=pk;++i)
            if (i%pi) ans=ans*i%pk;
        ans=fast_pow(ans,n/pk,pk);
    }
    for (ll i=2;i<=n%pk;++i)
        if (i%pi) ans=ans*i%pk;
    return ans*Mul(n/pi,pi,pk)%pk;
}
ll C(ll n,ll m,ll Mod,ll pi,ll pk)
{
    if (m>n) return 0ll;
    ll a=Mul(n,pi,pk),b=Mul(m,pi,pk),c=Mul(n-m,pi,pk);
    ll k=0ll,ans;
    for (ll i=n;i;i/=pi) k+=i/pi;
    for (ll i=m;i;i/=pi) k-=i/pi;
    for (ll i=n-m;i;i/=pi) k-=i/pi;
    ans=a*inv(b,pk)%pk*inv(c,pk)%pk*fast_pow(pi,k,pk)%pk;
    return ans*(Mod/pk)%Mod*inv(Mod/pk,pk)%Mod;
}
ll slove(ll n,ll m,ll p) //求C(n,m) mod p;
{
   for(ll x=p,i=2;i<=p;i++)
   {
     if(x%i == 0)
     {
       ll pk = 1;
       while(x%i == 0) pk*=i,x/=i;
       ans = (ans + C(n,m,mod,i,pk))%mod;
     }
   }
   return ans;
}
