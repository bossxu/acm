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
   while(t--)
   {
     ll shu[4],v;
     for(int i = 0;i<4;i++) cin>>shu[i];
     cin>>v;

     if(50>v)
     {
        int o = 50-v;
        shu[2]+=shu[3]*(o/10);
        o%=10;
        shu[1]+=shu[3]*(o/5);
        o%=5;
        shu[0]+=shu[3]*o;
     }
    // cout<<shu[0]<<endl;
     if(10>v)
     {
       int o = 10-v;
       shu[1]+=shu[2]*(o/5);
       o%=5;
       shu[0]+=shu[2]*o;
     }
    // cout<<shu[0]<<endl;
     if(5>v)
     {
       int o = 5-v;
       shu[0]+=o*shu[1];
     }
     cout<<shu[0]<<endl;
   }
  return 0;
}
