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
// 部分背包 开三维来写
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   int dp[105];
   while(t--)
   {
     int n,m;
     cin>>n>>m;
     int w[105],v[105],num[105];
     for(int i=1;i<=m;i++)
     {
       cin>>w[i]>>v[i]>>num[i];
     }
     clr(dp,0);
     for(int i=1;i<=m;i++)
     {
       for(int j=n;j>=0;j--)
       {
         for(int k=0;k<=num[i];k++)
         {
           if(j>=k*w[i])
           {
             dp[j]=max(dp[j-k*w[i]]+k*v[i],dp[j]);
           }
         }
       }
     }
     printf("%d\n",dp[n]);
   }

    return 0;
}
