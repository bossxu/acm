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
ll shu[100005];
ll dp[100005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   ll n,d;
   ll ans;
   dp[2] = 1;
   dp[0] = 0;dp[1]=0;
   for(int i = 3;i<=100000;i++)
   {
     dp[i] = dp[i-1] + i-1;
   }
   while(cin>>n>>d)
   {
     ans = 0;
     for(int i = 1;i<=n;i++)
     {
       scanf("%lld",&shu[i]);
     }
     int l = 1,r;
     for(int i = 1;i<=n;i++)
     {
       r = i;
       if(shu[i]-shu[1] > d)
       {
         r = i-1;
         break;
       }
     }
     for(int i = 1;i<=n;i++)
     {
       while(r<n && shu[r+1] - shu[i]<=d) r++;
       ans += dp[r-i];
     }
     cout<<ans<<endl;
   }
  return 0;
}
