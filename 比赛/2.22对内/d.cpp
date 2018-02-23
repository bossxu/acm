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
   ll dp[60];
   dp[1] = 1;
   dp[0] = 1;
   for(int i = 2;i<60;i++)
   {
     dp[i] = dp[i-1];
     if(i>=4)
     dp[i] += dp[i-3];
     else
     dp[i]+=dp[0];
   }
   int n;
   while(cin>>n)
    {
      if(n == 0) break;
      cout<<dp[n]<<endl;
    }
  return 0;
}
