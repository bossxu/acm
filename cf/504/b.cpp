#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,m;
  while(cin>>n>>m)
  {
    ll ans = 0;
    if(n>=m-1)
    {
      ans = m/2;
      if(m%2 == 0)
      ans--;
    }
    else
    {
      if(n <=m /2)
      {
        ans = 0;
      }
      else
      {
        ans = n-m/2;
        //if(m%2==0) ans--;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
