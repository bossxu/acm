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
int n;
const int maxn=42;
const double eps = 1e-6;
int main()
{
       freopen("/home/langman/桌面/acm/in.txt","r",stdin);
       freopen("/home/langman/桌面/acm/out.txt","w",stdout);
   ll dp[maxn];
   clr(dp,0);
   dp[0]=1,dp[1]=1;
   for(int i=2;i<=40;i++)
   {
     dp[i]=dp[i-1]+dp[i-2];
   }
   int t;
   dp[0]=0;
   cin>>t;
   while(t--)
   {
     cin>>n;
     cout<<dp[n-1]<<endl;
   }
  return 0;
}
