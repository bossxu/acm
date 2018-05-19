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
ll shu[200005];
int main()
{
  int n,m;
  std::ios::sync_with_stdio(false);
  while(cin>>n>>m)
  {
    shu[0] = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    int item = 1;
    ll ans = 0;
    ll a;
    for(int i = 1;i<=m;i++)
    {
      cin>>a;
      while(a>shu[item]+ans)
      {
        ans+=shu[item];
        item++;
      }
        cout<<item<<" "<<a-ans<<endl;
    }
  }
  return 0;
}
