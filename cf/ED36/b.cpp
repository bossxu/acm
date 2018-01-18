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
   int n,m,l,r;
   while(cin>>n>>m>>l>>r)
   {
     int sum = 0;
     if(m<l)
     {
       sum+=l-m+1;
       if(r!=n)
       sum+=r-l+1;
     }
     if(m>=l && m<=r)
     {
       if(l == 1)
       {
         if(r==n)
           sum = 0;
         else
         sum += r-m+1;
       }
       else if(r == n)
       {
         sum += m-l+1;
       }
       else
       {
         sum += min(m-l,r-m)+ r-l+2;
       }
     }
     if(m>r)
     {
       sum += m-r+1;
       if(l!=1)
       sum += r-l+1;

     }
     cout<<sum<<endl;
   }
  return 0;
}
