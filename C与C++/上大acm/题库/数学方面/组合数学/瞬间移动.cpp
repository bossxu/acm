#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const long long mod= 1e9+7;

ll dp[2000005];
//用乘法逆元的原因在于，加减乘，都可以直接对mod进行操作，但是除法不行。
void init()
{
    int i;
    dp[0]=1;
    for(i=1;i<=2000005;i++)
    {
        dp[i]=dp[i-1]%mod*i%mod ;
    }
}
void exgcd(ll a,ll b,ll& d,ll& x,ll& y) // 扩展欧几里得
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv(ll a, ll p) // 乘法逆元，这是利用扩展欧几里得的方法来写的
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}
//  当余数为素数时，还可以利用费马小定理来写，使用快速幂
// a（p-1）≡1  长知识了，留着

int main()
{
    int a,b;
    init();
    while(cin>>a>>b)
    {
      int m = a+b -4;
      int n = a-2;
      ll z = (dp[n]%mod)*(dp[m-n]%mod)%mod;
      z = inv(z,mod);
      z = (z%mod) *(dp[m]%mod) %mod;
      cout<<z<<endl;
      
    }
    return 0;
}