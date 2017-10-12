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
int a1[105],a2[105];
char s1[105],s2[105];
int dp[105][105];
void init()
{
   int n = strlen(s1);
   for(int i = 0;i<n;i++)
   {
     a1[i] = s1[i]-'a';
     a2[i] = s2[i]-'a';
   }
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  while(scanf("%s%s",s1,s2)!= EOF)
  {
    int n = strlen(s1);
    init();
    clr(dp,0);
    for(int j =0;j<=n;j++)
    {
      for(int i = 0;i+j<n ;i++)
      {
        dp[i][i+j] = dp[i+1][i+j]+1;
        for(int k =i+1;k<=i+j;k++)
        {
          if(a2[i] == a2[k])
          {
            dp[i][i+j] = min(dp[i][i+j],dp[i+1][k]+dp[k+1][i+j]);
          }
        }
      }
    }
    int ans[105];
    for(int i = 0;i<n;i++)
     ans[i] = dp[0][i];
    for(int i = 0;i<n;i++)
    {
       if(a1[i]==a2[i])
       ans[i] = ans[i-1];
       else
       {
         for(int j=0;j<i;j++)
         {
           ans[i] = min(ans[j]+dp[j+1][i],ans[i]);
         }
       }
    }
   cout<<ans[n-1]<<endl;
  }
  return 0;
}
