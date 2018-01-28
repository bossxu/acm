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
  //freopen("/home/langman/桌面/in.txt","r",stdin);
  //freopen("/home/langman/桌面/out.txt","w",stdout);
   for(ll i=1;i<=1e17;i++)
   {
      ll a;
      a=sqrt((i*i+i)/2);
      if(a*a*2== i*i+i)
      printf("%lld\n",i);
   }
   system("pause");
  return 0;
}
