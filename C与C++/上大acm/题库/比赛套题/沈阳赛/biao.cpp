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
int dfs(int k)
{
   int m;
   if(!k) return 0;
   k--;
   for(int i=0;i<=10005;i++)
   {
     
   }
}
int main()
{
  //freopen("/home/langman/桌面/in.txt","r",stdin);
  //freopen("/home/langman/桌面/out.txt","w",stdout);
   ll dp[10005];
   dp[0]=0,dp[1]=1;
   for(int i=2;i<=10005;i++)
   {
     dp[i]=dp[i-1]+dp[i-2];
   }
   for(int i=1;i<=10;i++)
   {
     dfs(i);
   }

  return 0;
}
