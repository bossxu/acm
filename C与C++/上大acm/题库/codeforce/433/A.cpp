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
int n;
const double eps = 1e-6;
int p[1005],q[1005];
int gcd( int a ,int  b)//公因数
{
     return a%b==0?b:gcd(b,a%b);
}
void init()
{
  for(int i=3;i<=1005;i++)
  {
      int a,b;
      a=i/2;b=i-a;
      while(gcd(a,b)!=1)
      {
        a--,b++;
      }
      p[i]=a,q[i]=b;
  }
}
int main()
{
   init();
   while(cin>>n)
   {
     printf("%d %d\n",p[n],q[n]);
   }
  return 0;
}
