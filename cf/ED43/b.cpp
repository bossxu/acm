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
   ll n,m,k;
   while(cin>>n>>m>>k)
   {
     if(k<=n-1)
     {
       cout<<k+1<<" 1"<<endl;
     }
     else
     {
       k-=n-1;
       ll dis = 2*m-2;
       ll l = k/dis;
       ll x = n-l*2;
       ll o = k%dis;
       if(o == 0) o = dis;
       ll y;
       if(o>m-1)
       {
         if(o == dis) x+=1;
         else x-=1;
          y=dis-o+2;
        }
       else
       {y = 1+o;}
       cout<<x<<" "<<y<<endl;
     }
   }
  return 0;
}
