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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll quick(ll a,ll b,ll m)
{
    ll ans=1;
    while(b!=0)
    {
        if(b&1) ans=(ans*a);
        b>>=1;
        a=(a*a);
        if(ans>m || (b!=0 && a>m))
        {
          return -1;
        }
    }
    return ans;
}

int main()
{
  ll n,m;
  while(cin>>n>>m)
  {
    ll p = quick(2,n,m);
    if(p == -1)
    {
      cout<<m<<endl;
    }
    else
    {
      cout<< m%p <<endl;
    }
  }
  return 0;
}
