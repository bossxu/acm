#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int prime[20];
ll N;int m;int i;
ll pan(ll num ,ll tem)
{
    if(num%tem==0) return num/tem-1;
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
  
    while(cin>>N>>m)
    {
        memset(prime,0,sizeof(prime));
        for(i=0;i<m;i++)
        {         
            cin>>prime[i];
            if(prime[i]==0 ) {i--;m--;}
        }
        ll ans= solve(N);
      printf("%lld\n",ans);
    }
    return 0;
}