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
int shu[30];
int dp[30];
int cmp(int a,int b)
{
  return a>b;
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n,m;
   while(cin>>n>>m)
   {
     if(n == 0 && m == 0) break;
     int sum1 = 0,sum2 = 0;
     int a;
     clr(shu,0);
     clr(dp,0);
     for(int i = 1;i<=n;i++)
     {
       cin>>a;
       shu[a]++;
     }
     for(int i = 1;i<=m;i++)
     {
       cin>>a;
       dp[a]++;
     }
     ll ans = 0;
    for(int i = 1;i<=20;i++)
      {
        ans+=max(dp[i],shu[i])*i;
      }
      cout<<ans<<endl;
   }
  return 0;
}
