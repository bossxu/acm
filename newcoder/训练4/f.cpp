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
int dp[60][60];
int n;
void floyd()
{
   for(int k = 1;k<=n;k++)
   {
     for(int i = 1;i<=n;i++)
     {
       for(int j = 1;j<=n;j++)
       {
         dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);
       }
     }
   }

}
int main()
{
   int m;
   while(cin>>n>>m)
   {
     clr(dp,0);
     for(int i = 1 ;i<= m;i++)
     {
       int a,b;
       cin>>a>>b;
       dp[a][b] = 1;
     }
     floyd();
     if(dp[1][n]) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
   }

  return 0;
}
