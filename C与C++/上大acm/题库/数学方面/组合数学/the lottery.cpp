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
ll prime[20];
ll n,m;
ll pan(ll num ,ll tem)
{
    if(num%tem==0) return num/tem;
    else return num/tem;
}
ll gcd( ll a ,ll b)
{
     return a%b==0?b:gcd(b,a%b);
}
ll big(ll tem ,ll a)
{
    return a/gcd(a,tem)*tem;
}
ll solve(ll num)  //好东西
{  
    ll i,j;  
    ll ans=0,tem,flag;  
    for(i=1;i<1<<m;i++)  
    {  
        tem=1,flag=0;  
        for(j=0;j<=m;j++)  
            if(i&1<<j)  
                {flag++;tem=big(tem,prime[j]);}  
        if(flag&1) 
        ans +=pan(num,tem); //容斥原理，奇加偶减  
        else ans -= pan(num,tem);  
    }  
    return ans;  
}
int main()
{
    while(scanf("%lld%lld",&n,&m)==2)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%lld",&prime[i]);
        }
        ll sum= n-solve(n);
   printf("%lld\n",sum);
    }
    return 0;
}