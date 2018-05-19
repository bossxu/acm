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
const int mod = 998244353;
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll quick(ll a,ll b)
{
  ll num = 1;
  while(b)
  {
    if(b&1)
    num = num*a%mod;
    a = a*a%mod;
    b/=2;
  }
  return num%mod;
}
int main()
{
   int n,m;
   while(cin>>n>>m)
   {
      cout<<m*quick(n*n,mod-2)%mod<<endl;
   }
  return 0;
}
