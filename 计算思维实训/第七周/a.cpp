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
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int main()
{
   int n;
   ll dp[1005];
   clr(dp,0);
   for(int i = 1;i<=n;i++)
   {
     dp[i] = i/2;
   }
   for(int j = 1;j<=1000;j++)
   {
     for(int i = 1;i<=j/2;i++)
     {
       dp[j] += dp[i];
     }
   }
   while(cin>>n)
 {
    cout<<dp[n]+1<<endl;
 }
  return 0;
}
