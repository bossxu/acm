#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case #"<<x<<": "
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
struct node
{
  ll x,y;
  friend bool operator<(node a,node b)
  {
    return a.x > b.x;
  }
}pre;
//这个是看的题解，看起来这个思路很简单。
//这个题的思路和我们之前想到的还是有区别的
// 这个明显简单多了，而且这个看起来好像可以直接去贪心。
// 仔细一想好像是有点道理，但是他那个贪心真的很难想到。
ll shu[1000006];
priority_queue<node>q1,q2;
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int t;cin>>t;
  int l,n,m;
  int tot = 0;
  while(t--)
  {
    while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();
    cin>>l>>n>>m;
    for(int i = 1;i<=n;i++)
    {
      cin>>pre.x;
      pre.y = pre.x;
      q1.push(pre);
    }
    for(int i = 1;i<=m;i++)
    {
      cin>>pre.x;
      pre.y = pre.x;
      q2.push(pre);
    }
    for(int i = 1;i<=l;i++)
    {
      pre = q1.top();
      shu[i] = pre.x;
      pre.x+=pre.y;
      q1.pop();
      q1.push(pre);
    }
    ll ma = 0;
    for(int i = l;i>0;i--)
    {
      pre = q2.top();
      ma = max(ma,shu[i]+pre.x);
      pre.x += pre.y;
      q2.pop();
      q2.push(pre);
    }
    c_fuck(++tot);
    cout<<ma<<endl;
  }
  return 0;
}
