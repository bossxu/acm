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
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll quick(ll a,ll p)
{
  ll res = 1;
  while(p)
  {
    if(p&1) res = res*a % mod;
    a = a*a % mod;
    p>>1;
  }
  return res;
}
int main()
{
   int n,m;
   int t;
   while(cin>>t)
   {

   }
  return 0;
}
