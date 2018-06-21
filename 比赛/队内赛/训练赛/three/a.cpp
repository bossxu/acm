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
   int n;
   cin>>n;
   while(n--)
   {
     ll m;
     cin>>m;
     int z = (m-1)%12;
     m%=10;
     int ans = m;
     for(int i = 1;i<=z;i++)
     {
       ans = ans*m%10;
     }
     cout<<ans<<endl;
   }
  return 0;
}
