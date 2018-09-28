//langman
#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
// 01分数规划的思想
// dp，重构价值来check()；
const int N = 1e5+5;
struct node
{
  int l,r;
  double a,b;
  double val;
}Q[N];
int n,r;
double tree[N];
int lowbit(int t)
{
  return t&(-t);
}
void add(int x,double y)
{
  for(int i=x;i<=r;i+=lowbit(i))
    tree[i]=max(tree[i],y);
}
double getmax(int x)
{
  double ans=0;
  for(int i=x;i>0;i-=lowbit(i))
    ans = max(ans,tree[i]);
  return ans;
}
bool check(double st)
{
  for(int i = 1;i<=n;i++)
  {
    Q[i].val = Q[i].a - Q[i].b*st;
  }
  clr(tree,-INF);
  tree[0] = 0;
  double ans = -1;
  for(int i = 1;i<=n;i++)
  {
    double op = getmax(Q[i].l-1)+Q[i].val;
    cout<<getmax(Q[i].l-1)<<endl;
    add(Q[i].r,op);
  }
  ans = getmax(r);
  return ans>0;
}
int cmp(node k,node p)
{
  if(k.l == p.l)
  {
    return k.r<p.r;
  }
  return k.l<p.l;
}
int main()
{
  ios_close;
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>r;
    double li = 0,ri = 1000;
    for(int i = 1;i<=n;i++)
    {
      cin>>Q[i].l>>Q[i].r>>Q[i].a>>Q[i].b;
      Q[i].val = 0;
    }
    sort(Q+1,Q+n+1,cmp);
    double ans = 0;
    while(ri-li>eps)
    {
      cout<<ri<<" "<<li<<endl;
      double mid = (li+ri)/2;
      if(check(mid))
      {
        ans = mid;
        li = mid;
      }
      else
      {
        ri = mid;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
