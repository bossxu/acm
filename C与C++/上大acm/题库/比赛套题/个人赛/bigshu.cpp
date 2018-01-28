#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int mod=10;
int quick(ll n , ll b)
{
    ll c =1;
    while(b!=0)
     {
        if  (b%2==1) c = (c%mod) * (n%mod) % mod;
        n = n%mod *n%mod ;
        b/=2; 
     }
     return c%mod;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a;
        cin>>a;
        printf("%d\n",quick(a,a));

    }
    return 0;
}