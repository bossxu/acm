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
   int dp[21],sum[21];
   int n;
   while(cin>>n)
   {
     clr(dp,0);clr(sum,0);
     for(int i = 1;i<n;i++)
     {
       int a,b;
       cin>>a>>b;
       dp[a]++,dp[b]++;
     }
     for(int i = 1;i<=n;i++)
     {
       sum[dp[i]]++;
     }
     int p = 0;
     for(int i =1;i<=n;i++)
     {
       p = p^sum[i];
     }
     if(p) cout<<"First"<<endl;
     else cout<<"Second"<<endl;
   }
  return 0;
}
