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
// 改变背包的容量的题,数据很水 wa 的原因在于没想到概率是相乘的关系 
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   double dp[10005];
   int m[105];
   double p[105];
   while(t--)
   {
     double P;
     int n;
     cin>>P>>n;
     int sum=0;
     for(int i=1;i<=n;i++)
     {
       cin>>m[i]>>p[i];
       p[i]=1-p[i];
       sum+=m[i];
     }
     for(int i=0;i<=n;i++)
     {
       for(int j=sum;j>=0;j--)
       {
         if(i==0)
         {
           dp[j]=0;
           if(j==0)
           dp[j]=1;
           continue;
         }
         dp[j+m[i]] = max(dp[j]*p[i],dp[j+m[i]]);
       }
     }
    int i;
    for(i = sum;i >0;i--)
    {
      //cout<<dp[i]<<endl;
      if(1-dp[i]<=P)
      break;
    }
    cout<<i<<endl;

   }
  return 0;
}
