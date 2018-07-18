#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll dp[2020];
void init()
{
  for(int i  = 1;i<=2017;i++)
  {
    for(int j = 1;j<=2018;j++)
    {
      if((i*j)%2018 == 0)
      {
        dp[i] = j;
        break;
      }
    }
  }
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  ll l,r,l1,r1;
  ll mo = 2018;
  init();
  while(scanf("%lld%lld%lld%lld",&l,&r,&l1,&r1) == 4)
  {
    ll ansl = 0;
    ll ansb = 0;
    ll ansc = 0;
    for(int i = 1;i<2018;i++)
    {
      ll ok = r1/dp[i] - (l1-1)/dp[i];
      if(i>=l%2018) ansl+=ok;
      if(i<=r%2018) ansc+=ok;
      ansb+=r1/dp[i] - (l1-1)/dp[i];
    }
    int num = r/mo - (l-1)/mo;
    int flag = (r-l - 2018 + (l%2018)- (r%2018))/2018;
    ll ans = ansl + ansc + ansb*(flag) + num*(r1-l1+1);
    printf("%lld\n",ans);
  }
  return 0;
}
