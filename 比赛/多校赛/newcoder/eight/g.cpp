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

ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    a = a*a%mod;
    b>>=1;
  }
  return res;
}

int main()
{
  ios_close;
  ll n;
  while(cin>>n)
  {
    if(n == 3) {cout<<1<<endl;continue;}
    if(n == 5) {cout<<11<<endl;continue;}
    ll fan = quick(1LL*24,mod-2);
    ll op = quick(1LL*2,mod-2);
    ll shang = n*(n-1)%mod;
    shang = shang*(n-2)%mod;
    shang = shang*(n-3)%mod;
    ll is = (n-1)*(n-2)%mod;
    cout<<((fan*shang%mod)+(op*is%mod))%mod<<endl;
  }
  return 0;
}
