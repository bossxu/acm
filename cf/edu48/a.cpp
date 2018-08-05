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
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
ll shu[200005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    ll ans = 0;
    ll rev = 0;
    for(int i = 1;i<=n;i++)
    {
      rev += shu[i];
      ans = rev/m;
      rev%=m;
      cout<<ans<<" ";
    }
    cout<<endl;
  }

  return 0;
}
