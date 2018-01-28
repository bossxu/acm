#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const long long mod= 1e4+7;
long long factorial[10000]; 
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
long long mod_pow(int a,int n,int p)  
{  
    long long ret=1;  
    long long A=a;  
    while(n)  
    {  
        if (n & 1)  
            ret=(ret*A)%p;  
        A=(A*A)%p;  
        n>>=1;  
    }  
    return ret;  
}   
void init()  
{  
    factorial[0] = 1;  
    for(int i = 1;i <= mod;i++)  
        factorial[i] = factorial[i-1]*i%mod;  
    //for(int i = 0;i < p;i++)  
        //ni[i] = mod_pow(factorial[i],p-2,p);  
}  
  
long long Lucas(long long a,long long k,long long p) //求C(n,m)%p p最大为10^5。a,b可以很大！  
{  
    long long re = 1;  
    while(a && k)  
    {  
        long long aa = a%p;long long bb = k%p;  
        if(aa < bb) return 0; //这个是最后的改动！  
        re = re*factorial[aa]*mod_pow(factorial[bb]*factorial[aa-bb]%p,p-2,p)%p;//这儿的求逆不可先处理  
        a /= p;  
        k /= p;  
    }  
    return re;  
}  
int main()
{
    ll N;
    init();
    while(cin >> N)
    {
      N--;
      ll c = Lucas(2*N,N,mod);
      ll z = quick(N+1,mod-2);
       c = (c%mod) *(z%mod) %mod ;       
      cout<< (c *2)%mod<<endl;
    }
    return 0;
}

