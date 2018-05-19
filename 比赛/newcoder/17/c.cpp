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
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll shu[2005];
ll dp[2005];
ll quick(ll a,ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b&1) ans = ans*a%mod;
    b/=2;
    a = a*a%mod;
  }
  return ans%mod;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n;
   ll k;
   while(cin>>n>>k)
   {
     dp[0] = 1;
     for(int i = 1;i<=n;i++)
     {
       dp[i] = (dp[i-1]*(k+i-1))%mod*quick(i,mod-2)%mod;
     }
     //for(int i = 1;i<=n;i++) cout<<
     for(int i = 1;i<=n;i++)
     {
       cin>>shu[i];
     }
     cout<<shu[1];
     for(int i =2;i<=n;i++)
     {
       ll flag = 0;
       for(int j = 1;j<=i;j++)
       {
         flag  = (flag + (shu[j]*dp[i-j])%mod)%mod;
       }
       cout<<" "<<flag;
     }
     cout<<endl;
   }
  return 0;
}
