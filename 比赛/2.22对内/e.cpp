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
int main()
{
   ll dp[1005];
   clr(dp,0);
   for(int i = 0;i<=100;i++)
   {
     for(int j = 0;j<=50;j++)
     {
       for(int k = 0;k<=20;k++)
       {
         for(int l = 0;l<=10;l++)
         {
           int z =10*i+20*j+50*k+l*100;
           if(z<=1000)
           {
             dp[z]++;
           }
         }
       }
     }
   }

   int n;
   dp[0] = 0;
   while(cin>>n)
   {
     cout<<dp[n]<<endl;
   }
  return 0;
}
