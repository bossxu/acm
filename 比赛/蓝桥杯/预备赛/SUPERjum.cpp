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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n;
   ll date[1005];
   ll dp[1005];
   while(cin>>n)
   {
     if(!n) break;
     clr(dp,0);
     ll maxn = 0;
     for(int i = 1;i<=n;i++)
     cin>>date[i];
     for(int i = 1;i<=n;i++)
     {
       for(int j=1;j<i;j++)
       {
         if(date[i]>date[j])
         dp[i] = max(dp[j],dp[i]);
       }
       dp[i]+=date[i];
       maxn = max(dp[i],maxn);
     }
     cout<<maxn<<endl;
   }
  return 0;
}
