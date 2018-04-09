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
int main()
{
   ll dp[40];
   clr(dp,0);
   dp[1] = 1;
   dp[0] = 1;

   for(int i = 2;i<=30;i++)
   {
      for(int j = i;j>0;j--)
      {
        dp[i] += dp[i-j];
      }
   }
   int n;
   int t;
   cin>>t;
   while(t--)
   {
     cin>>n;
     cout<<dp[n]<<endl;
   }
  return 0;
}
