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
  cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
     int l1,r1,st1,d1;
     int l2,r2,st2,d2;
     int k;
     cin>>l1>>r1>>st1>>d1;
     cin>>l2>>r2>>st2>>d2;
     cin>>k;
     if(d1 == 0) d1 = -1;
     if(d2 == 0) d2 = -1;
     int ans = 0;
     if(st1 == st2) ans++;
     while(k)
     {
       int next1,next2;
       if(st1 == r1)
       {
         d1 = -1;
       }
       if(st1 == l1)
       {
         d1 = 1;
       }
       next1 = st1+d1;
       if(st2 == r2)
       {
         d2 = -1;
       }
       if(st2 == l2)
       {
         d2 = 1;
       }
       st1+=d1,st2+=d2;
       if(st1 == st2) ans++;
       k--;
     }
     cout<<ans<<endl;
   }
  return 0;
}
