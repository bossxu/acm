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
struct matrix      //我用一个结构体来存
{
      ll a[2][2];
}origin,res;          //顺便直接搞两个夺下赶出来。
void init()
{
    origin.a[0][0]=1;                   //原始的数组初始化。
    origin.a[0][1]=1;
    origin.a[1][0]=1;
    origin.a[1][1]=0;
    memset(res.a,0,sizeof(res.a));                        //归零话
    res.a[0][0]=res.a[1][1]=1;                  //将res.a初始化为单位矩阵
}
matrix multiply(matrix x,matrix y)                            //    矩阵的乘法
{
       matrix temp;
       memset(temp.a,0,sizeof(temp.a));
       for(int i=0;i<2;i++)
       {
               for(int j=0;j<2;j++)
               {
                       for(int k=0;k<2;k++)
                       {
                               temp.a[i][j]=(temp.a[i][j]+(x.a[i][k]*y.a[k][j])%mod)%mod;
                       }
               }
       }
       return temp;
}
void calc(ll n)                             //核心的代码
{
     while(n)
     {
             if(n&1)
                    res=multiply(res,origin);
             n>>=1;
             origin=multiply(origin,origin);
     }
}
ll quick(ll a,ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b&1) ans = ans*a%mod;
    a = a*a%mod;
    b/=2;
  }
  return ans%mod;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  ll x,y;
  while(cin>>x>>y)
  {
    if(y%x || x>y)
    {
      cout<<0<<endl;
      continue;
    }
    ll k = y/x;
    init();
    calc(k-1);
    cout<<((quick(2,k-1) - res.a[0][1])%mod+mod)%mod<<endl;
  }

  return 0;
}
