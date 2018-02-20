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
ll num(ll a)
{
  ll sum = 0;
    while(a>=100)
    {
    sum += a/100;
    a = a%100;
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
   ll n,p;
   int m;
   ll dp[122];
   while(cin>>n>>m>>p)
   {
     clr(dp,INF);
     dp[0] = 0;
     for(int i = 1;i<=m;i++)
     {
       dp[i] = num(i*p);
     }
     for(int i = 1;i<=m;i++)
     {
       for(int j = i;j<=100;j++)
       {
         dp[j] = min(dp[j],dp[j-i]+dp[i]);
       }
     }
     ll sum = dp[1]*n;
    // cout<<sum<<endl;
     for(int i = 2;i<=m;i++)
     {
       ll o = dp[i] * n/i + dp[n%i];
       int p = n%i;
       ll cha = 0;

       for(int j = 1;j*i+p<=min((ll)100,n);j++)
       {
         cha = min(dp[j*i+p] - dp[p] - j*dp[i],cha);
       }
       o+=cha;
       sum = min(o,sum);
     }
     cout<<sum<<endl;
   }
  return 0;
}
