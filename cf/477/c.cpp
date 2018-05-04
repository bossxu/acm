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
ll l[100005];
ll e[100055];
ll up(ll a,ll b)
{
  if(a%b == 0) return a/b;
  else return a/b+1;
}
int main()
{
//  freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n,m,cl,ce,v;
   while(cin>>n>>m>>cl>>ce>>v)
   {
     for(int i = 1;i<=cl;i++) cin>>l[i];
     for(int j = 1;j<=ce;j++) cin>>e[j];
     int q;
     cin>>q;
     int x1,y1,x2,y2;
     ll ans;
     for(int i = 1;i<=q;i++)
     {
       cin>>y1>>x1>>y2>>x2;
       if(x1>x2)
       {
         int t;
         t = x1,x1 = x2,x2 = t;
       }
       e[0] = -INF,l[0] = -INF;
       if(ce == 0)
        e[1] = INF;
       if(cl == 0)
        l[1] == INF;
        if(y1== y2) {cout<<abs(x2-x1)<<endl;continue;}
       int item = lower_bound(e+1,e+ce+1,x1) - e;
       if(item>ce && ce) item--;
       int flag = lower_bound(l+1,l+cl+1,x1) - l;
       if(flag>cl && cl) flag--;
       if(e[item]>=x1 && e[item]<=x2)
       {
         ans = up(abs(y1-y2),v)+(x2-x1);
         cout<<ans<<endl;
       }
       else
       {
         ll ans1,ans2;
         if(e[item]<x1)
         ans1 = up(abs(y1-y2),v)+(x1-e[item])*2+x2-x1;
         else
         ans1 = up(abs(y1-y2),v)+min((e[item]-x2),x1-e[item-1])*2+x2-x1;
         //cout<<l[flag]<<endl;
         if(l[flag]<x1)
         {
           ans2 = abs(y1-y2)+x2-x1+2*(x1-l[flag]);
           //cout<<ans2<<endl;
         }
         else
         {
           if(l[flag]<=x2)
           ans2 = abs(y1-y2)+x2-x1;
           else
           ans2 = abs(y1-y2)+x2-x1+2*min((l[flag]-x2),x1-l[flag-1]);
         }
         cout<<min(ans1,ans2)<<endl;
       }
       //cout<<item<<endl;
     }
   }
  return 0;
}
