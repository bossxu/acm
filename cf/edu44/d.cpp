#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
#define mod 2e9
ll op(ll n)
{
  return n*(n+1)/2;
}
int main()
{
  std::ios::sync_with_stdio(false);
  ll n,h;
  while(cin>>n>>h)
  {
    ll l = 1,r = mod;
    ll mid;
    while(l<r)
    {
      mid = (l+r)/2;
      if(mid*(mid+1)/2 == n) break;
      if(mid*(mid+1)/2 > n)
      {
        r = mid-1;
      }
      else
      {
        l = mid+1;
      }
    }
    while(op(mid+1)<=n) mid++;
    while(op(mid)>n) mid--;
    ll ans = 0;
    if(mid<=h) {
      if(op(mid) == n)
      {
        cout<<mid<<endl;
      }
      else
      {
        cout<<mid+1<<endl;
      }
    }
    else
      {
        n-=op(h);
        cout<<mid<<endl;
        ans+=h;
        if(n%h) ans++;
        ans+=n/h;
        cout<<ans<<endl;
      }
    }


  return 0;
}
