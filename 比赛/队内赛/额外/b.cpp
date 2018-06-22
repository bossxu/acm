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
   ll n,m;
   double a,b;
   int t;
   cin>>t;
   double s1,s2;
   while(t--)
   {
     cin>>n>>m>>a>>b;
     s1 = 0,s2 = 0;
     s1 += n*(1-b) + n*b*a + m*b*a;
     s2 += m*b + m*(1-b)*a + n*(1-b)*a;
     if(s1>s2) {
       cout<<"tiger ";
       printf("%.4lf\n",s1);
     }
     else
     {
       cout<<"wolf ";
       printf("%.4lf\n",s2);
     }

   }

  return 0;
}
