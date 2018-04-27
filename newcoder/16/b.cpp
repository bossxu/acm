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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int shu[100005];
int dp[300005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n;
   while(cin>>n)
   {
     for(int i = 1;i<=n;i++)
     {
       scanf("%d",&shu[i]);
     }
     int mid = n/2;
     int mid2;
     mid2 = mid+1;
     clr(dp,0);
     for(int i = 1;i<=mid;i++)
     {
       shu[i]-=i;
     }
     for(int i = n,k = 1;i>=mid2;i--,k++)
     {
       shu[i]-=k;
     }
     for(int i = 1;i<=n;i++)
     {
       shu[i]+=15000;
     }
     for(int i = 1;i<=n;i++)
     {
       dp[shu[i]]++;
     }
     int ans = 0;
     for(int i = 1;i<=300000;i++)
     {
       ans = max(ans,dp[i]);
     }
     cout<<n-ans<<endl;
   }
  return 0;
}
