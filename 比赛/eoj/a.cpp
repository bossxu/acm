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
int num(int a)
{
  int sum = 0;
    while(a>=100)
    {
      a-=100,sum++;
    }
    while(a>=50)
    {
      a-=50,sum++;
    }
    while(a>=20)
    {
      a-=20,sum++;
    }
    while(a>=10)
    {
      a-=10;sum++;
    }
    while(a>=5)
    {
      a-=5;sum++;
    }
    while(a>=1)
    {
      a-=1;sum++;
    }
  return sum;
}
int main()
{
   int n,m,p;
   int dp[12];
   int sum[1005];
   while(cin>>n>>m>>p)
   {
     clr(dp,0);
     clr(sum,INF);
     for(int i = 1;i<=m;i++)
     {
       dp[i] = num(i*p);
     }
     for(int i = 1;i<=m;i++)
     {
       for(int j = 1;j<i;j++)
       {
         dp[i] = min(dp[i],dp[i-j]+dp[j]);
       }
     }
     sum[0] = 0;
     for(int i = 1;i<=m;i++)
     {
       for(int j = i;j<=n;j++)
       {
         sum[j] = min(sum[j],sum[j-i]+dp[i]);
       }
     }
     cout<<sum[n]<<endl;
   }
  return 0;
}
