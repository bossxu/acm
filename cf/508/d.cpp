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
ll shu[500005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    clr(shu,0);
    ll minn = INF;
    ll maxn = -INF;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      minn = min(shu[i],minn);
      maxn = max(shu[i],maxn);
    }
    if(n == 1)
    {
      cout<<shu[1]<<endl;
      continue;
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      ans += abs(shu[i]);
    }
    if(minn >=0)
    {
      ans -= 2*minn;
    }
    if(maxn <= 0)
    {
      ans -= 2*abs(maxn);
    }
    cout<<ans<<endl;
  }
  return 0;
}
