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
ll shu[100005];
int main()
{
  std::ios::sync_with_stdio(false);
  int n;
  ll w;
  while(cin>>n>>w)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    ll ans = 0;
    ll maxn =0;
    ll item = 0;
    for(int i = 1;i<=n;i++)
    {
        ll item = 0;
        for(int j = i;j<=n;j++)
        {
          item += shu[j];
          maxn = max(abs(item),maxn);
        }
    }
    ans = w-maxn+1;
    cout<<(ans<0?0:ans)<<endl;

  }
  return 0;
}
