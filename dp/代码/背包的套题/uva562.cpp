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
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     int n;
     cin>>n;
     int s=0;
     int a[105];
     int dp[50005];
     clr(dp,-INF);
     for(int i=1;i<=n;i++)
     {
       cin>>a[i];
       s+=a[i];
     }
     dp[0]=0;
     for(int i=1;i<=n;i++)
     {
       for(int j=s/2;j>=a[i];j--)
       {
         if(dp[j-a[i]]>-INF)
         {
           dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
         }
       }
     }
     int k = s/2;
     while(dp[k]<0) k--;
     cout<<s-2*k<<endl;
   }

    return 0;
}
