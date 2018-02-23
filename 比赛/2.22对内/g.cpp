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
int xbs(int a)
{
  return a>0?a:0;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int dp[2005];
     int x[2005],f[2005];
     int l,n;
     cin>>l>>n;
     for(int i = 1;i<=n;i++)
     scanf("%d",&x[i]);
     for(int i = 1;i<=n;i++)
     {
       scanf("%d",&f[i]);
     }
     clr(dp,0);
     int index = 0;
     for(int i = 0;i<=l;i++)
     {
       for(int j = 1;j<=n;j++)
       {
         dp[i]+=xbs(f[j]-abs(i-x[j]));
       }
       if(dp[i]<dp[index])
       {
         index = i;
       }
     }
     cout<<index<<" "<<dp[index];
   }
  return 0;
}
