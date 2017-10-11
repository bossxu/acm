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
// 水题
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n,m;
   int dp[13000];
   int w[3500],d[3500];
   while(cin>>n>>m)
   {
      for(int i= 1;i<=n;i++)
      {
        cin>>w[i]>>d[i];
      }
      clr(dp,0);
      for(int i=1;i<=n;i++)
      {
        for(int j=m;j>=w[i];j--)
        {

          dp[j] = max(dp[j-w[i]]+d[i],dp[j]);
        }
      }
     cout<<dp[m]<<endl;
   }
  return 0;
}
