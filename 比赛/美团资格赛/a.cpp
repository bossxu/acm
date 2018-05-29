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
double a[15];
double vis[15];
double c[15],b[15];
#define ko 0.8
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n,m;
   while(cin>>n>>m)
   {
     for(int i = 1;i<=n;i++)
     {
       cin>>a[i]>>vis[i];
     }
     for(int i = 1;i<=m;i++)
     {
       cin>>c[i]>>b[i];
     }
     double l = 0,r;
     double kk = 0;
     for(int i = 1;i<=n;i++)
     {
       if(vis[i] == 1) l += ko*a[i];
       else l+=a[i];
       kk += a[i];
     }
     r = kk;
     for(int i = 1;i<=m;i++)
     {
       if(kk>=c[i]) r = min(r,kk-b[i]);
     }
     printf("%.2f\n",min(l,r));

   }
  return 0;
}
