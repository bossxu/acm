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

char s[10000006];
ll dp[4100][4100];
ll shu[5000];
int main()
{
  scanf("%s",s);
  ll k,x1;
  ll a,b,c,d,e;
  scanf("%lld%lld%lld%lld%lld%lld",&x1,&a,&b,&c,&d,&e,&k);
  clr(dp,0);
  ll ans = 0;
  int len = strlen(s);
  for(int i = 0;i<len;i++)
  {
    ans = (ans*10+s[i]-'0')%mod;
  }
  ll pre = x1;
  ll st,x;
  int tot = 0;
  for(int i = 1;i<=k;i++)
  {
    st = e-1;
    x = pre;
    st = (st + d*x)%k;x = x*pre%k;
    (st += c*x) %= k,(x*=pre)%=k;
    (st += b*x) %= k,(x*=pre)%=k;
    (st += a*x) %= k,pre = st;
    shu[st]++;
    tot++;
    if(shu[st]) break;
  }
  ll op = ans/(tot-1);
  ll end = st;
  st = -1,pre = st;
  while(st!=end)
  {
    st = e-1;
    x = pre;
    st = (st + d*x)%k;x = x*pre%k;
    (st += c*x) %= k,(x*=pre)%=k;
    (st += b*x) %= k,(x*=pre)%=k;
    (st += a*x) %= k,pre = st;
    shu[st]+=op;
  }
  ll ci = ans%(tot-1);
  while(ci--)
  {
    st = e-1;
    x = pre;
    st = (st + d*x)%k;x = x*pre%k;
    (st += c*x) %= k,(x*=pre)%=k;
    (st += b*x) %= k,(x*=pre)%=k;
    (st += a*x) %= k,pre = st;
    shu[st]+=1;
  }
  return 0;
}
