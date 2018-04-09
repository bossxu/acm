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
ll dp[2][100000];
int num[2][100000];
int fen(ll o,int flag)
{
  int len = 0;
  for(int i = 2;i<=(int)sqrt(o);i++)
  {
    if(o%i == 0)
    {
      dp[flag][len] = i;
      while(o%i==0)
      {
        o/=i;
        num[flag][len]++;
      }
      len++;
    }
  }
  if(o!=1)
  {
    dp[flag][len] = o;
    num[flag][len]++;
    len++;
  }
  return len;
}
int main()
{
   ll x,a,y,b;
   int t;
   cin>>t;
   while(t--)
   {
     clr(dp,0);
     clr(num,0);
     cin>>x>>a>>y>>b;
     if(x == 1)
     {
       if(y == 1)
       {
         cout<<"Yes"<<endl;
       }
       else
       cout<<"No"<<endl;
       continue;
     }
     if(y == 1)
     {
       cout<<"No"<<endl;
       continue;
     }
     int o = fen(x,0);
     int p = fen(y,1);
     if(o!=p)
     {
       cout<<"No"<<endl;
       continue;
     }
     else
     {
       int flag = 1;
       for(int i = 0;i<o;i++)
       {
         if(dp[0][i]!=dp[1][i]) flag = 0;
         if(num[0][i]*a != num[1][i]*b) flag = 0;
       }
       if(flag)
       cout<<"Yes"<<endl;
       else
       cout<<"No"<<endl;
     }

   }
  return 0;
}
