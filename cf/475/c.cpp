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
const int mod = 1000000009;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
char s[100005];
ll quick(ll a,ll b)
{
  //cout<<a<<endl;
  ll res = 1;
  while(b)
  {
    if(b&1)
    res = (res*a)%mod;
    a = (a%mod)*(a%mod)%mod;
    b/=2;
  }
  //cout<<res<<endl;
  return res%mod;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   ll n;
   ll a,b;
   ll k;
   while(cin>>n>>a>>b>>k)
   {
     cin>>s;
    // cout<<s<<endl;
     int flag = -1;
     ll ans = 0;
     for(int i = 0;i<k;i++)
     {
       if(s[i] == '+')
        flag = 1;
       else
       flag = -1;

        ans += (quick(a,n-i)*quick(b,i)%mod)*flag;
        ans += mod;
        ans %= mod;
        //cout<<flag<<s[i]<<endl;
        //cout<<ans<<endl;
     }
     ans=(ans+mod)%mod;
     //cout<<ans<<endl;
     ll a1 = quick(a,mod-2);
     ll a2 = quick(a1,k)%mod*quick(b,k)%mod;
     ll ok = (n+1)/k;
       if(a2 == 1)
       {
         cout<<ans%mod*ok%mod<<endl;
         continue;
       }
       else
       {
         ll op = (quick(a2,ok)-1+mod)%mod*quick(a2-1,mod-2)%mod;
         cout<<ans%mod*op%mod<<endl;
       }

   }
  return 0;
}
