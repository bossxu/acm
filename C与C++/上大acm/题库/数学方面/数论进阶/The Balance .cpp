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
#include<map>
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
const double eps = 1e-6;
// 知识点分解：扩展欧几里得 poj 2142
ll gcd(ll a,ll b)
{
   return a%b==0?b:gcd(b,a%b);
}
void exGcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return;
    }
    exGcd(b,a%b,y,x);
    y-=a/b*x;
}
int main()
{
    ll a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c)==3 && (a||b||c))
    {
      ll x,y,x1,y1;
      ll k=gcd(a,b);
      a/=k,b/=k,c/=k;
      exGcd(a,b,x,y);
      exGcd(b,a,y1,x1);
      x*=c;
      x= (x%b+b)%b;
      y= (c-a*x)/b;
      y=y<0?-y:y;
      y1*=c;
      y1= (y1%a+a)%a;
      x1= (c-b*y1)/a;
      x1=x1<0?-x1:x1; 
      
      if(x1+y1<x+y)
      {
          x=x1; y=y1;
      }
      printf("%lld %lld\n",x,y); 
    }
    system("pause");
    return 0;
}