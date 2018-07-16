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
//很巧苗的一个或的运算题,这个思路值得收藏
//从最高位来思考问题,分析区间每个区间的头.太强了,这个想法.
ll go(ll a,ll b,ll v,ll bis)
{
  if(bis == -1) return 1;
  bool ai = a>>bis&1 , bi =b>>bis&1 , vi = v>>bis&1;
  if(vi && !ai && !bi)
  {
    return b-a+1;
  }
  if(!vi && ai && bi)
  {
    return 0;
  }
  if(!vi && !ai && !bi)
  {
    return go(a,b,v,bis-1);
  }
  if(vi && ai && bi)
  {
    return go(a & ~(1LL<<bis),b & ~(1LL<<bis),v & ~(1LL<<bis),bis-1);
  }
  if(!vi && !ai && bi)
  {
    return go(a,(1LL<<bis)-1,v,bis-1);
  }
  if(v == (1LL<<(bis+1))-1)
  {
    return b-a+1;
  }
  ll c = (1LL<<bis) - 1;
  return max(c-a+1,go((c+1) & ~(1LL<<bis),b&~(1LL<<bis),v&~(1LL<<bis),bis-1));
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    ll a,b,v;
    scanf("%lld%lld%lld",&a,&b,&v);
    cout<<go(a,b,v,59)<<endl;
  }
  return 0;
}
