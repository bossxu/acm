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
int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n;
   ll dp[30];
   dp[0] = 1;
   for(int i = 1;i<=24;i++)
   {
     dp[i] = dp[i-1]*3;
   }
   while(cin>>n)
   {
     if(n == -1) break;
     if(n == 0)
     {
       cout<<0<<endl;
       continue;
     }
     ll ans = 0;
     for(int i = 1;i<=n;i++)
     {
       int k = gcd(n,i);
       ans+=dp[k];
     }
     if(n%2 == 1)
     {
       ans+= n*(dp[n/2+1]);
     }
     else
     {
       ans+=n/2*(dp[n/2]+dp[n/2+1]);
     }
     cout<<ans/2/n<<endl;
   }
  return 0;
}
