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
ll a[1005];
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(a&1) res = res*a%mod;
    b = b*b%mod;
    a/=2;
  }
  return res;
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[0] = 0;
    ll ans = quick(a[1],n);
    for(int i = 2;i<=n;i++)
    {
      ans = ans + a[1]*quick(a[2],)
    }
  }
  return 0;
}
