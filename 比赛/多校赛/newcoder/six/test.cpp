#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll  unsigned long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;

ll gcd(ll a,ll b)
{
  return b == 0?a:gcd(b,a%b);
}

int main()
{
  ll o,p;
  while(cin>>o>>p)
  {
    cout<<gcd(o,p)<<endl;
    cout<<o*p<<endl;
  }
  return 0;
}
