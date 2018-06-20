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
int shu[100005];
int dp[100005];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  //std::ios::sync_with_stdio(false);
   int t;
   scanf("%d",&t);
   int n;
   while(t--)
   {
     scanf("%d",&n);
     for(int i = 1;i<=n;i++)
     {
       scanf("%d",&shu[i]);
     }
     ll ans = 0;
     for(int i = 0;i<=20;i++)
     {
       ll cnt = 0;
       for(int j = 1;j<=n;j++)
       {
         if(shu[j]&(1<<i))
         {
           cnt++;
         }
         else
         {
           ans+=(cnt*(cnt+1))/2*(ll)(1<<i);
           //cout<<cnt<<endl;
           cnt = 0;
         }
       }
       ans+=(cnt*(cnt+1))/2*(1<<i);
     }
     cout<<ans<<endl;
   }
  return 0;
}
