#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define ull unsigned long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 1e5+6;
int num[N+5];
int prim[N+6];
int mark[N+6];
int cnt;
// 一道很纯粹的推公式的题，写起来很舒服
void init()
{
  cnt=0;
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
int main()
{
  ios_close;
  int t;
  init();
  scanf("%d",&t);
  while(t--)
  {
    ll n;
    scanf("%lld",&n);
    ll op = n;
    ll ans = 1;
    for(int i = 0;prim[i]*prim[i]<=n;i++)
    {
      if(n%prim[i] == 0)
      {
        int num = 0;
        ll mu = 1;
        ll chu = prim[i];
        while(n%prim[i] == 0) mu = mu*prim[i], num++,n/=prim[i];
        op = op*(num+1); mu = mu*prim[i]; //(mul^2-1) / (prim^2-1)
        ll a = (mu-1)/(prim[i]-1),b = mu+1,c = prim[i]+1;
        ans *=((a/c)*(b/c)*c) + a%c*(b/c) + b%c*(a/c);
      }
    }
    if(n!=1)
    {
      ll chu = n;
      op*=2;
      ans*=chu*chu+1;
    }
    printf("%lld\n",ans-op);
  }
  return 0;
}
