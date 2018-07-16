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
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll shu[500005];
ll gcd(ll a, ll b)
{
  return b == 0?a:gcd(b,a%b);
}
set<ll>all;
set<ll>q[2];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      all.insert(shu[i]);
    }
    q[1].insert(shu[1]);
    int flag = 1;
    for(int i = 2;i<=n;i++)
    {
      int next = flag^1;
      q[next].insert(shu[i]);
      for(set<ll>::iterator t = q[flag].begin();t!=q[flag].end();t++)
      {
        all.insert(*t);
        q[next].insert(gcd(*t,shu[i]));
      }
      q[flag].clear();
      flag^=1;
    }
    for(set<ll>::iterator t = q[flag].begin();t!=q[flag].end();t++)
    {
      all.insert(*t);
    }
    cout<<all.size()<<endl;
    all.clear();
  }
  return 0;
}
