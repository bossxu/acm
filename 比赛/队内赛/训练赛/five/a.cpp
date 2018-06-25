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
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int t;
   cin>>t;
   ll n,k;
   while(t--)
   {
    cin>>n>>k;
    if(k == 0)
    {
      cout<<n<<endl;
      continue;
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      ll num = 1;
      for(int j = 1;j<=k;j++)
      {
        num = num*i%mod;
      }
      ans = (ans+num)%mod;
    }
    cout<<ans<<endl;
   }
  return 0;
}
