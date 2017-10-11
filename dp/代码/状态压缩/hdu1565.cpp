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
bool check(int x)
{
  if(x & x<<1) return 0;
  return 1;
}
ll dp[21][20000];
ll shu[21][20000];
int map[21][21];
int n;
void get(int x,int z)
{
  int k,i;
  for(i=1;i<=n;i++)
  {
     k = x;
     for(int j=n;j>0;j--,k/=2)
       {
         if(k%2==1)
         shu[i][z] += map[i][j];
       }
  }
}
bool suit(int x, int y)
{
  if(x&y) return 0;
  else return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>n)
    {
      clr(dp,0);
      clr(shu,0);
      int k = 0;
      int ok[20000];
      for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
         cin>>map[i][j];
      for(int i=0;i<1<<n;i++)
      {
        if(check(i))
        {
           get(i,k);
           ok[k++] = i;
        }
      }
      for(int i = 0;i<k;i++)
         dp[1][i] = shu[1][i];
      for(int i = 2;i<=n;i++)
      {
         for(int j = 0;j<k;j++)
          {
            for(int l =0;l<k;l++)
            {
              if(suit(ok[l],ok[j]))
              {
                dp[i][j] = max(dp[i][j],dp[i-1][l]+shu[i][j]);
              }
            }
          }
      }
      ll ans =0;
    for(int i= 0;i<k;i++)
     {
       //cout <<ok[i]<<endl;
       ans = max(ans,dp[n][i]);
     }
     cout<<ans<<endl;
    }
    return 0;
}
