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
#define ll long long
#define clr(a,x) memset(a,x,sizeof(a))
int check(ll p,ll o)
{
  ll num = 0;
  ll c = p;
  while(p>0)
  {
    num+=min(p,o);
    p-=o;
    p = p - p/10;
  }
  return num*2>=c;
}
int main()
{
  ll n;
  std::ios::sync_with_stdio(false);
  while(cin>>n)
  {
    ll l = 1;
    ll r = n;
    ll ans = 0;
    ll mid = (l+r)/2;
    while(l<=r)
    {
      //cout<<l<<"  "<<r<<endl;
      mid = (l+r)/2;
      ll zhong = check(n,mid);
      if(zhong)
      {
        ans = mid;
        r = mid-1;
      }
      else
      {
        l = mid+1;
      }
    }
  cout<<ans<<endl;
  }
  return 0;
}
