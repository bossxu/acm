#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using  namespace std;
long long mod;

long long  digui(long long a,long long b)
{
    long long c=1;
    while(b>0)
    {
        if(b%2==1)
            c=c*a%mod;
        b/=2;
        a=(a%mod)*(a%mod);
    }
    return c;
}
int main()
{
    long long a,b;
    int  T;
    cin>>T;
    int n,i;
    while(T--)
    {
        long long sum=0;
        scanf("%lld%d",&mod,&n);
        while(n--)
        {
           scanf("%lld%lld",&a,&b);
            sum=(sum+digui(a,b))%mod;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
