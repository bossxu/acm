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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int n;ll m;
struct node
{
  ll cost;
  ll liang;
  ll bi;
}shu[33];
bool cmp(node a,node b)
{
  if(a.bi == b.bi)
  {
    return a.cost*b.liang < b.cost*a.liang;
  }
   return a.bi<b.bi;
}
ll sum;
ll dfs(ll l,int k)
{
  ll u = 0;
  //cout<<l<<endl;
  if(l>=shu[k].liang)
  {
    ll o = l/shu[k].liang;
    l -= o*shu[k].liang;
    u += shu[k].cost*o;
    //cout<<sum<<endl;
  }
    if(l == 0) return u;
    //cout<<u<<endl;
    int i = 1;
    ll costm = shu[k].cost;
    ll costn = shu[k].cost;
    while(i<=n)
    {
      if(shu[i].liang > l)
      costm = min(shu[i].cost,costm);
      if(shu[i].liang<=l)
      {
        ll o = dfs(l,i);
        costn = min(o>0?o:costn,costn);
      }
      i++;
    }

    if(costn>=costm)
    {
      u += costm;
    }
    else
    u+=costn;
    return u;
}
int main()
{
  while(cin>>n>>m)
  {
    ll c = 1;
    for(int i = 1;i<=n;i++)
    {
       cin>>shu[i].cost;
       shu[i].liang = c;
       c*=2;
       shu[i].bi = shu[i].cost/shu[i].liang;
    }
   sort(shu+1,shu+n+1,cmp);
    sum = dfs(m,1);
    cout<<sum<<endl;
  }

  return 0;
}
