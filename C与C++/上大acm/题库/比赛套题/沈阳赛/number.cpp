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
#define mod 998244353
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
struct matrix
{
      ll a[2][2];
}origin,res;
void init()
{
    origin.a[0][0]=1;
    origin.a[0][1]=1;
    origin.a[1][0]=1;
    origin.a[1][1]=0;
     memset(res.a,0,sizeof(res.a));
     res.a[0][0]=res.a[1][1]=1;
}
matrix multiply(matrix x,matrix y)
{
       matrix temp;
       memset(temp.a,0,sizeof(temp.a));
       for(int i=0;i<2;i++)
       {
               for(int j=0;j<2;j++)
               {
                       for(int k=0;k<2;k++)
                       {
                               temp.a[i][j]+=(x.a[i][k]*y.a[k][j])%mod;
                       }
               }
       }
       return temp;
}
void calc(ll n)
{
     while(n)
     {
             if(n&1)
                    res=multiply(res,origin);
             n>>=1;
             origin=multiply(origin,origin);
     }
}
int main()
{
  ll n;
  while(cin>>n)
  {
    init();
    calc(2*n+2);
    printf("%lld\n",(res.a[0][0]-1)%mod);
  }
  return 0;
}
