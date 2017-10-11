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
int map[105];
const int maxn = 64;
int dp[105][maxn][maxn];
int num[105];
int getnum(int x)//用来得到数位上1的个数
{
  int ret = 0;
   while(x)
   {
       x &= x-1;
       ++ret;
   }
   return ret;
}
bool suit(int x,int y)
{
  if(x&y)  return 0;
  return 1;
}
bool check(int x)
{
  if(x&(x<<1)) return 0;
  if(x&(x<<2)) return 0;
  return 1;
}
int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int n,m;
   while(cin>>n>>m)
   {
     clr(map,0);
     clr(dp,-1);
     clr(num,0);
     for(int i = 1;i<=n;i++)
     {
       char c[12];
       scanf("%s",c);
       for(int j =0;j<m;j++)
       {
         if(c[j]=='H')
         map[i] = map[i]*2+1;
         else
         map[i] = map[i]*2;
       }
     }
     int ok[1<<10];
     int k = 0;
     for(int i=0;i<1<<m;i++)
     {
       if(check(i))
       {
         num[k] = getnum(i);
         ok[k++] = i;
       }
     }
   for(int i=0;i<k;i++)
   {
     if(suit(ok[i],map[1]))
     {
       dp[1][i][0] =num[i];
     }
   }
   for(int i=2;i<=n;i++)
   {
     for(int j=0;j<k;j++)
     {
       if(suit(ok[j],map[i]))
       {
         for(int l =0;l<k;l++)
        {
          if(suit(ok[l],ok[j]))
          {
            for(int z=0;z<k;z++)
            {
              if(dp[i-1][l][z] == -1 || !suit(ok[z],ok[j]))
              continue;
              dp[i][j][l] = max(dp[i][j][l],dp[i-1][l][z]+num[j]);
            }
          }
        }
       }
     }
   }
   int ans = 0;
  for(int i = 0;i<k;i++)
   for(int j =0;j<k;j++)
     ans = max(ans,dp[n][i][j]);
     cout<<ans<<endl;
   }
  return 0;
}
