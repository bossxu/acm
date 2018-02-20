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
const int maxn = 100005;
int n;
ll a[maxn],m[maxn];//a余数 m除数
ll gcd(ll a,ll b) {
    return !b?a:gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y) {
    if (!b) {
        x=1,y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
ll inv(ll a,ll m) {
    ll x,y;
    ll d=exgcd(a,m,x,y);
    if (d==-1) return -1;
    return (x%m+m)%m;
}
bool merge(ll a1,ll m1,ll a2,ll m2,ll &a3,ll &m3) {
    ll d=gcd(m1,m2),c=a2-a1;
    if (c%d) return false;
    c=(c%m2+m2)%m2,
    c/=d,m1/=d,m2/=d,
    c*=inv(m1,m2),
    c=(c%m2+m2)%m2,
    c=(c*m1*d)+a1;
    m3=m1*m2*d;
    a3=(c%m3+m3)%m3;
    return true;
}
ll crt() {
    ll a1=a[1],m1=m[1];
    for (int i=2;i<=n;i++) {
        ll aa,mm;
        if (!merge(a1,m1,a[i],m[i],aa,mm)) return -1;
        a1=aa,m1=mm;
    }
    return (a1%m1+m1)%m1;
}
int main()
{
   while(cin>>n)
   {
     for(int i = 1;i<=n;i++)
     {
       scanf("%lld%lld",&m[i],&a[i]);
       //cout<<a[i]<<m[i]<<endl;
     }
     cout<<crt()<<endl;
   }

  return 0;
}
