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
#define in(x) scanf("%d",&x);
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 500005;
struct node
{
  ll x,y;
  bool operator < (const node &A) const
  {
    if(x == A.x)
    {
      return y>A.y;
    }
    return x < A.x;
  }
}shu[N];
ll dp[N];
ll x[N],y[N];
ll q[N];
ll ship(int i,int j)
{
  return 1.0*(dp[i]-dp[j])/(y[i+1]-y[j+1]);
}
int main()
{
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  int n;
  while(scanf("%d",&n) == 1)
  {
    for(int i = 1;i<=n;i++)
    {
      scanf("%lld%lld",&shu[i].x,&shu[i].y);
    }
    sort(shu+1,shu+n+1);
    int tot = 0;
    for(int i = 1;i<=n;i++)
    {
      for(;tot && shu[i].y>=y[tot];tot--);
      x[++tot] = shu[i].x;
      y[tot] = shu[i].y;
    }
    dp[0] = 0;
    int head = 1,tail = 1;
    for(int i = 1;i<=tot;i++)
    {
      while(head!=tail && ship(q[head],q[head+1])>=-x[i]) head++;
      dp[i] = dp[q[head]] + x[i]*y[q[head]+1];
      while(head!=tail && ship(q[tail-1],q[tail]) < ship(q[tail],i)) tail--;
      q[++tail] = i;
    }
    cout<<dp[tot]<<endl;
  }
  return 0;
}
