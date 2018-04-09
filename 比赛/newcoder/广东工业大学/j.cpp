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
   int t;
   cin>>t;
   int dp[100005];
   while(t--)
   {
     int n;
     ll sum = 0;
     int minn = INF;
     cin>>n;
     for(int i = 1;i<=n;i++)
     {
       cin>>dp[i];
       sum+=dp[i];
       minn = min(dp[i],minn);
     }
     ll o = 0;
    for(int j = 1;j<=n;j++)
    {
      o+=dp[j]-minn;
    }

      cout<<o<<" "<<(o*n-o+sum)/n<<endl;
   }
  return 0;
}
