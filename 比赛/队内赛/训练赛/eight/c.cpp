#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
map<ll, ll>p;
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  while(cin>>q)
  {
    int flag;
    ll u,v,quan;
    for(int i = 1;i<=q;i++)
    {
      cin>>flag;
      if(flag == 1)
      {
        cin>>u>>v>>quan;
        while(u!=v)
        {
          if(u>v)
          {
            int item = p.count(u);
            if(item) p[u]+=quan;
            else p[u] = quan;
            u/=2;
          }
          else
          {
            int item = p.count(v);
            if(item) p[v]+=quan;
            else p[v] = quan;
            v/=2;
          }
        }
      }
      if(flag == 2)
      {
        cin>>u>>v;
        ll ans = 0;
        while(u!=v)
        {
          if(u>v)
          {
            int item = p.count(u);
            if(item) ans+=p[u];
            u/=2;
          }
          else
          {
            int item = p.count(v);
            if(item) ans+=p[v];
            v/=2;
          }
        }
        cout<<ans<<endl;
      }
    }

  }

  return 0;
}
