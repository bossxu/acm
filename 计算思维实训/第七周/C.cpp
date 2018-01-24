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
int main()
{
   int n,v;
   int shu[35];
   bool dp[20005];
   while(cin>>v>>n)
   {
     clr(dp,0);
     for(int i = 1;i<=n;i++)
     {
       cin>>shu[i];
     }
     dp[0] = 1;
     for(int i = 1;i<=n;i++)
     {
        for(int j = v;j>=shu[i];j--)
        {
          dp[j] = dp[j-shu[i]] || dp[j];
        }
     }
     for(int i = v;i>=0;i--)
     {
       if(dp[i])
       {
         cout<<v-i<<endl;
         break;
       }
     }
   }
  return 0;
}
