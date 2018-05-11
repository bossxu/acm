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
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
#define lson rt<<1
#define rson rt<<1|1
//区间更新模板题
const int maxn = 100005;
ll a[maxn];
int lazy[maxn];
struct node
{
  int l,r;
  ll s;
}tree[maxn<<2];
void pushup(int rt)
{
  tree[rt].s = tree[lson].s+tree[rson].s;
}
void pushdown(int rt ,int len)
{
  if(lazy[rt])
  {
    lazy[lson] = lazy[rson] = lazy[rt];
    tree[lson].s = lazy[rt]*(len-(len>>1));
    tree[rson].s = lazy[rt]*(len>>1);
    lazy[rt] = 0;
  }
}
void build(int rt, int l, int r)//建树
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].s = 1;
    return ;
  }
  int mid = (l+r)>>1;
  build(lson,l,mid);
  build(rson,mid+1,r);
  pushup(rt);
}
void duan_up(int rt,int l,int r,int m)
{
  //cout<<tree[rt].l<<"  "<<tree[rt].r<<" "<<tree[rt].s<<endl;
  if(tree[rt].l>=l && tree[rt].r<=r)
  {
    lazy[rt] = m;
    tree[rt].s = m*(tree[rt].r-tree[rt].l+1);
    return;
  }
  pushdown(rt,tree[rt].r-tree[rt].l+1);
  int mid = (tree[rt].l+tree[rt].r)>>1;
  if(l<=mid) duan_up(lson,l,r,m);
  if(r>mid) duan_up(rson,l,r,m);
  pushup(rt);
}
int query(int rt,int l,int r)
{
  //cout<<l<<"  "<<r<<endl;
  if(l <= tree[rt].l && r >= tree[rt].r) return tree[rt].s;
  pushdown(rt,tree[rt].r-tree[rt].l+1);
  int mid = (tree[rt].l+tree[rt].r)/2;
  int ans= 0;
  if(l <= mid)  ans+= query(lson,l,r);
  if(r>mid)    ans+= query(rson,l,r);
  return ans;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  int flag = 0;
  int n,q;
  while(t--)
  {
    clr(lazy,0);
    cin>>n>>q;
    int l,r,u;
    build(1,1,n);
    while(q--)
    {
      cin>>l>>r>>u;
      duan_up(1,l,r,u);
    }
    cout<<"Case "<<++flag<<": The total value of the hook is "<<query(1,1,n)<<"."<<endl;
    int n;
  }

  return 0;
}
