#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int gcd( int  a ,int b)//公因数
{
     return a%b==0?b:gcd(b,a%b);
}
int main()
{
   int T;
   cin>>T;
   int count=0;
   while(T--)
   {
       int n,a,b;
       cin>>n>>a>>b;
       n=n/gcd(a,b);
       if(n%2==0) printf("Case #%d: Iaka\n",++count);
       else printf("Case #%d: Yuwgna\n",++count);   
   }
    return 0;
}