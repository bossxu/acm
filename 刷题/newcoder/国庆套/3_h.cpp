// langman
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
const int N = 1e5+5;
// 很强的思路 ，是说把这个转化成的问题为 把树分成m个联通块。
// 是 C(n-1,m-1) 断边就可以，然后这个还有顺序
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<n;i++)
    {
      int u,v;
      cin>>u>>v;
    }
    ll ans = m;
    for(int i = n-m+1;i<=n-1;i++)
    {
      ans = ans*i%mod;
    }
    cout << ans<<endl;
  }
  return 0;
}
