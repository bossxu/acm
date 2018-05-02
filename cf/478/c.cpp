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
ll a[200005];
ll k[200005];
ll dp[200005];
int main()
{
   int n,q;
   while(cin>>n>>q)
   {
     for(int i = 1;i<=n;i++)
     {
       cin>>a[i];
     }
     for(int i = 1;i<=q;i++)
     {
       cin>>k[i];
     }
     dp[0] = 0;
     for(int i = 1;i<=n;i++)
     {
       dp[i] = dp[i-1]+a[i];
     }
     ll st;
     ll ans = 0;
     for(int i = 1;i<=q;i++)
     {
       int index = lower_bound(dp+1,dp+n+1,k[i]+ans) - dp;
      // cout<<index<<" ";
       if(index == n+1)
       {
         ans = 0;
         cout<<n<<endl;
       }
       else
       {
         if(dp[index] == k[i]+ans)
         {
           if(n-index == 0)  {cout<<n<<endl;ans = 0;}
           else {cout<<n-index<<endl;ans+=k[i];}
         }
         else
         {cout<<n-index+1<<endl;
         ans+=k[i];}
       }
     }
   }
  return 0;
}
