#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define LL ll
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 1e4+5;
ll inv = (mod+1)/2;
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = a*res%mod;
    b>>=1;
    a = a*a%mod;
  }
  return res;
}
bool mark[N];
int prim[N];
int cnt;
ll inv6;
void initial()
{
    cnt=0;
    inv6 = quick(6*1LL,mod-2);
    for (int i=2 ; i<N ; ++i)
    {
        if (!mark[i])
            prim[cnt++]=i;
        for (int j=0 ; j<cnt && i*prim[j]<N ; ++j)
        {
            mark[i*prim[j]]=1;
            if (!(i%prim[j]))
                break;
        }
    }
}
ll cal_1(ll n)
{
  return n*(n+1)%mod*inv%mod;
}
ll cal_f(ll n)
{
  return n*(n+1)%mod*(2*n+1)%mod*inv6%mod;
}
vector<int>q;
int main()
{
  ll n,m;
  initial();
  ios_close;
  while(cin>>n>>m)
  {
    q.clear();
    for(int i = 0;i<cnt;i++)
    {
      if(m<prim[i]) break;
      if(m%prim[i] == 0) q.pb(prim[i]);
      while(m%prim[i] == 0) m/=prim[i];
    }
    if(m!=1) q.pb(m);
    int len = q.size();
    ll ans = (cal_1(n) + cal_f(n))%mod;
    //cout<<ans<<endl;
    for(int i = 1;i<(1<<len);i++)
    {
      int op = 0;
      ll st = 1;
      for(int j = 0;j<len;j++)
      {
        if(i &(1<<j))
        {
          st = st*q[j];
          op^=1;
        }
      }
      //cout<<st<<endl;
      if(!op)
      {
        ans = (ans + st*st%mod*cal_f(n/st)%mod)%mod;
        ans = (ans+ st*cal_1(n/st)%mod)%mod;
      }
      else
      {
        ans = (ans-st*st%mod*cal_f(n/st)%mod +mod)%mod;
        ans = (ans-st*cal_1(n/st)%mod +mod)%mod;
      }
    }
    cout<<(ans+mod)%mod<<endl;
  }
  return 0;
}
