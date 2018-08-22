#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int T;
    scanf("%d",&T);
    ll a,b,c,a1,b1,c1;
    while(T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&a1,&b1,&c1);
        if(a1>=b1&&a1>=c1)
        {
            ll p=(a1-b1-c1)*(c-b);
            if(p%(a+b+c)==0)
            {
                printf("%lld\n",p/(a+b+c));
            }
            else
            {
                ll d=gcd(p,(a+b+c));
                printf("%lld/%lld\n",p/d,(a+b+c)/d);
            }
        }
        else if(b1>=a1&&b1>=c1)
        {
            ll p=(b1-a1-c1)*(a-c);
            if(p%(a+b+c)==0)
            {
                printf("%lld\n",p/(a+b+c));
            }
            else
            {
                ll d=gcd(p,(a+b+c));
                printf("%lld/%lld\n",p/d,(a+b+c)/d);
            }
        }
        else
        {
            ll p=(c1-a1-b1)*(b-a);
            if(p%(a+b+c)==0)
            {
                printf("%lld\n",p/(a+b+c));
            }
            else
            {
                ll d=gcd(p,(a+b+c));
                printf("%lld/%lld\n",p/d,(a+b+c)/d);
            }
        }
    }
}
