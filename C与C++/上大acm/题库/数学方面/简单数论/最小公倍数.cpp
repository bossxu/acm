#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
long long gcd(ll a,ll b)
{
   return a%b==0?b:gcd(b,a%b);
}
int main()
{
    int T;
    ll a;
	cin >> T;
	while(T--)
	{
	  int n;
	  ll i,k=1,z;
	  scanf("%lld",&n);
	  while(n--)
	  {
		  scanf("%lld",&a);
		  if(a==0 || k==0) 
		  {
			  k=0;continue;
		  }
		  z=gcd(k,a);
		  k=k/z*a;
	  }
      printf("%lld\n",k);
	}
	return 0;
}