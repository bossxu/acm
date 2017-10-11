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
const int mod = 1e8 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
bool check(int x)     //检查是否左右有相同的值
{
  if(x & x<<1) return 0;
  return 1;
}
bool suit(int x,int c)
{
  if(x&c) return 0;
  return 1;
}
int map[13];
int dp[13][1<<12];
int ok[1<<12];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,m;
  while(cin>>n>>m)
  {
    clr(map,0);
    clr(dp,0);
    for(int i =1;i<=n;i++)
    {
      for(int j =1;j<=m;j++)
      {
        int a;
        scanf("%d",&a);
        a=!a;
        map[i] = (map[i]<<1)+a;
      }
     //  cout<<map[i]<<endl;
    }
    int k = 0;
    for(int i =0;i<1<<m;i++)
    {
      if(check(i))
      ok[k++] = i;
    }
    for(int i=0;i<k;i++)
    {
      if(suit(map[1],ok[i]))
      dp[1][i] = 1;
    }
    for(int i =2;i<=n;i++)
    {
      for(int j =0;j<k;j++)
      {
        if(suit(ok[j],map[i]))
        {
          for(int l=0;l<k;l++)
          {
            if(suit(ok[l],ok[j]))
            dp[i][j]= (dp[i-1][l]+dp[i][j])%mod;
          }
        }
      }
    }
 int ans =0;
      for(int i=0;i<k;i++)
      {
        //printf("%d,%d\n",dp[n][i],ok[i]);
         ans = (ans+dp[n][i])%mod;
      }
       cout<<ans<<endl;

  }
  return 0;
}
