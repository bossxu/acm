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
ll dp[1000005];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=1000000;i++)
  {
    dp[i] = dp[i-1]*i%mod;
  }
}
int main()
{
  ll n;
  init();
  while(cin>>n)
  {
    cout<<(dp[n-1]*dp[n-1]%mod)*(n*n*2%mod)%mod<<endl;
  }

  return 0;
}
