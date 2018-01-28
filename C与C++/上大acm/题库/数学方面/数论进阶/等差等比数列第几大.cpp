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
#define mod 200907
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
// 知识点分解：快速幂
long long  quick(long long a,long long b)
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
    ll a,b,c;
    ll k;
    int t;
    cin>>t;
    while(t--)
    {
        ll z;
        cin>>a>>b>>c>>k;
        if(c-b == b-a)
        {
            z = c-b;
            z = a%mod + (((k-1)%mod)*(z%mod))%mod;
            z%=mod;
        }
        else
        {
           z =b/a;
           z = (a%mod) *(quick(z,k-1)%mod) %mod;
        }
        printf("%lld\n",z);
    }
    //system("pause");
    return 0;
}