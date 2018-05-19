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
//striring 公式
//n！= sqrt(2*PI*n) * (n/e)^n
int main()
{
   int n;
   int t;
   cin>>t;
  // init();
   while(t--)

   {
     scanf("%d",&n);
     if(n == 0 || n==1) cout<<1<<endl;
     else
     {
       long double  res = ( log(2 * pi * n) / 2.0 + n * log( n / loge ) )/log(8)+1;
       printf("%ld\n",(ll)res);
     }
   }
  return 0;
}
