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
const long long mod = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
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
long long  quick(long long a,long long b)
{
    long long c=1;
    while(b>0)
    {
        if(b%2==1)
            c=c*a%mod;
        b/=2;
        a=(a%mod)*(a%mod)%mod;
    }
    return c%mod;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  while(t--)
  {
    ll p ,q ,k;
    cin>>p>>q>>k;
    ll r = p-q,c,b;
    if(r>=q)
     c =quick(r-q,k) + quick(p,k);
    else
     c =-quick(q-r,k) + quick(p,k);
    c%=mod;
    b = quick(p,k)*2 ;
    b%=mod;
    cout<<c*quick(b,mod-2)%mod<<endl;
  }
  return 0;
}
