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
double a[500005];
double p[500005];
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     int n,m;
     cin>>n>>m;
     for(int i = 1;i<=n;i++)
     {
       cin>>a[i];
     }
     for(int j = 1;j<=m;j++)
     {
       cin>>p[j];
     }
     for(int j=1;j<=m;j++){
       int ans = 0;
     for(int i = 1;i<=n;i++)
     {
       ans+=floor(a[i]/ceil(log(a[i])/p[j]));
     }
     cout<<ans<<endl;
   }

   }
  return 0;
}
