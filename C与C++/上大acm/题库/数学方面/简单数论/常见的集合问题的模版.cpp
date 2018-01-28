#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int shu[10000];
int z;
void init( ll n)//初始化公因数
{
    z=0;int i,c=n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0) {shu[z++]=i;while(n%i==0) n/=i;}
    }
   if(n>1) shu[z++]=n;
}
ll gcd( ll a ,ll b)//公因数
{
     return a%b==0?b:gcd(b,a%b);
}
ll big(ll tem ,ll a)//公倍数
{
    return a/gcd(a,tem)*tem;
}
ll solve(ll num)  //好东西
{  
    ll i,j;  
    ll ans=0,tem,flag;  
    for(i=1;i<1<<z;i++)  
    {  
        tem=1,flag=0;  
        for(j=0;j<z;j++)  
            if(i&(ll)1<<j)  
                {flag++;tem=tem*shu[j];}  
        if(flag&1) 
        ans +=num/tem; //容斥原理，奇加偶减  
        else ans -=num/tem;  
    }  
    return ans;  
}
int main()
{
  int T;
  cin>>T;
  int cou=1;
  while(T--)
  {
      ll a,b,N;
      ll s;
      scanf("%lld%lld%lld",&a,&b,&N);
      if(N==1) printf("Case #%d: %lld\n",cou++,b-a+1);
     else
     { init(N);
      printf("Case #%d: %lld\n",cou++,b-a+1-solve(b)+solve(a-1));
     }
  }
  //system("pause");
    return 0;
}