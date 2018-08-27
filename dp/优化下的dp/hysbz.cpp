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
const int N = 500005;
struct node
{
  ll l,r;
  bool operator < (const node &A) const
  {
    return l<A.l;
  }
}shu[N];
ll dp[N];
ll x[N],y[N];
ll q[N];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i].l>>shu[i].r;
    }
    sort(shu+1,shu+n+1);
    int tot = 0;
    for(int i = 1;i<=n;i++)
    {
      for(;tot && shu[i].y>=y[tot]);
      x[++tot] = shu[i].x;
      y[tot] = shu[i].y;
    }
    dp[0] = 0;
    int head = tail = 1;
    for(int i = 1;i<=tot;i++)
    {
      while(head!=tail && )
    }
  }
  return 0;
}
