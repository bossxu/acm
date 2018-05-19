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
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int main()
{
   int n;
   while(cin>>n)
   {
     int shu[105];
     int l,r;
     for(int i = 1;i<=n;i++)
     {
       cin>>shu[i];
       if(shu[i] == 1)
       {
         l = i;
       }
       if(shu[i] == n)
       {
         r = i;
       }
     }
     if(r<l)
     {
       int t = l;
       l = r;
       r = t;
     }
     //cout<<l<<"->"<<r<<endl;
     cout<<(r-l)+max(n-r,l-1)<<endl;

   }
  return 0;
}
