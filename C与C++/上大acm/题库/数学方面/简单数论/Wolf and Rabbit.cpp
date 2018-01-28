#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
   return a%b==0?b:gcd(b,a%b);
}

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    ll a,b;
    cin>>a>>b;
    if(gcd(a,b)==1) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}