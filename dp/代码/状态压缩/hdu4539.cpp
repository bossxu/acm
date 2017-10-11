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
int dp[105][200][200];
int map[105];
int num[200];
bool check(int x)
{
  if(x & x<<2) return 0;
  return 1;
}
int getnum(int x)
{
  int ret = 0;
  while(x)
  {
    x &= x-1;
    ret++;
  }
  return ret;
}
bool suit(int x, int y)
{
  if(x&y) return 0;
  else return 1;
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int n,m;
  while(scanf("%d%d",&n,&m)==2)
   {
     clr(map,0);
     clr(dp,-1);
     for(int i=1;i<=n;i++)
     {
       for(int j=1;j<=m;j++)
       {
         int a;
         scanf("%d",&a);
         a = !a;
         map[i] = (map[i]<<1)+a;
       }
     }
     int k=0;
     int ok[200];
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
       if(suit(map[1],ok[i]))
        dp[1][i][0] = num[i];
     }
     for(int i=2;i<=n;i++)
     {
       for(int j = 0;j<k;j++)
       {
         if(suit(map[i],ok[j]))
         {
            for(int l = 0;l<k;l++)
            {
              if(suit(ok[j],ok[l]<<1) && suit(ok[j]<<1,ok[l]))
              {
                for(int z = 0;z<k;z++)
                {
                  if(dp[i-1][l][z] != -1 && suit(ok[j],ok[z]))
                  {
                    //printf("--%d--%d--%d\n",i,ok[j],map[i]);
                    dp[i][j][l] = max (dp[i-1][l][z]+num[j],dp[i][j][l]);
                  }
                }
              }
            }
         }
       }
     }
      int ans = 0;
      for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
          ans = max(dp[n][i][j],ans);
    cout<<ans<<endl;
   }
  return 0;
}
