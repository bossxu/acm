#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
const int maxn=14;
int n;
ll a[maxn],m[maxn];
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
int main() {
    while(scanf("%d",&n)!=EOF) {
        for (int i=1;i<=n;i++) scanf("%I64d%I64d",&m[i],&a[i]);
        printf("%I64d\n",crt());
    }
    return 0;
}
