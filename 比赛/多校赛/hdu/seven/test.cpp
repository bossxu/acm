#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;

int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}
ll phi(ll n) //直接实现
{
  ll rea = n;
  for(int i = 2;i*i<=n;i++)
  {
    if(n%i == 0)
    {
      rea = rea - rea/i;
      while(n%i == 0) n/=i;
    }
  }
  if(n>1)
  rea = rea - rea/n;
  return rea;
}
//欧拉打表
int n,m,p;
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1)
    res = res*a%p;
    a = a*a%p;
    b/=2;
  }
  return res;
}

int main()
{
  while(cin>>n)
  {
  //  ll ans = 0;
    cout<<phi(n)<<endl;
    // cout<<ans<<endl;
  }
  return 0;
}
