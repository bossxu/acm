#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
//线性基处理问题，第一次碰见。
char s[10000005];
int vis[1<<13];
ll a,b,c,d,e;
ll x,k;
vector<int>q;
struct Linear_Basis
{
    ll d[63],p[63],tot;
    void init()
    {
        tot=0;
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
    }
    bool ins(ll x)
    {
        for(int i=62;i>=0;i--)
            if (x&(1LL<<i))
            {
                if (!d[i]) {d[i]=x;break;}
                x^=d[i];
            }
        return x>0;
    }
} LB;
int slove()
{
  int len = q.size();
  LB.init();
  int ans = 0;
  for(int i = 0 ;i<len;i++)
  {
    //cout<<q[i]<<endl;
    if(LB.ins(q[i])) ans++;
  }
  return ans;
}
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    b>>=1;
    a = a*a%mod;
  }
  return res;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(cin>>s>>x)
  {
    cin>>a>>b>>c>>d>>e;
    cin>>k;
    ll ans = 0;
    clr(vis,0);
    int len = strlen(s);
    for(int i = 0;i<len;i++)
    {
      ans = ans*10 + s[i]-'0';
      ans %= mod-1;
    }
    //cout<<ans<<endl;
    q.clear();
    ll next,now;
    next = now = x;
    int tot = 0;
    while(!vis[next] && tot<ans)
    {
      tot++;
      ll op = now;
      next = e-1;
      (next += d*op)%=k,(op*=now)%=k;
      (next += c*op)%=k,(op*=now)%=k;
      (next += b*op)%=k,(op*=now)%=k;
      (next += a*op)%=k,next+=1;
      vis[now] = 1;
      q.pb(now);
      now = next;
    }
    int st = slove();
    //cout<<st<<endl;
    cout<<(quick(2,ans)-quick(2,ans-st)+mod)%mod<<endl;
  }
  return 0;
}
