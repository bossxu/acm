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
int shu[200005];
vector<int>t[200005];
vector<int>path[200005];
int tot;
void dfs(int st)
{
  path[st].push_back(tot+1);
  for(int i = 0;i<t[st].size();i++)
  {
    dfs(t[st][i]);
  }
  tot++;
  path[st].push_back(tot);
}
#define lson rt<<1
#define rson rt<<1|1
//区间更新模板题 这是区间变一个值
const int maxn = 200005;
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
void pushdown(int rt)
{
  if(lazy[rt])
  {
    lazy[lson]^=1;
    lazy[rson]^=1;
    tree[lson].s = tree[lson].r+1-tree[lson].l - tree[lson].s;
    tree[rson].s = tree[rson].r+1-tree[rson].l - tree[rson].s;
    lazy[rt] = 0;
  }
}
void build(int rt, int l, int r)//建树
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].s = shu[l];
    return ;
  }
  int mid = (l+r)>>1;
  build(lson,l,mid);
  build(rson,mid+1,r);
  pushup(rt);
}
void duan_up(int rt,int l,int r,int m)
{
  if(tree[rt].l>=l && tree[rt].r<=r)
  {
    lazy[rt] ^= m;
    tree[rt].s = tree[rt].r-tree[rt].l+1-tree[rt].s;
    return;
  }
  pushdown(rt);
  int mid = (tree[rt].l+tree[rt].r)>>1;
  if(l<=mid) duan_up(lson,l,r,m);
  if(r>mid) duan_up(rson,l,r,m);
  pushup(rt);
}
int query(int rt,int l,int r)
{
  //cout<<l<<r<<endl;
  if(l <= tree[rt].l && r >= tree[rt].r) return tree[rt].s;
  pushdown(rt);
  int mid = (tree[rt].l+tree[rt].r)/2;
  int ans= 0;
  if(l <= mid)  ans+= query(lson,l,r);
  if(r>mid)    ans+= query(rson,l,r);
  return ans;
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
    int pre;
    for(int i = 2;i<=n;i++)
    {
        cin>>pre;
        t[pre].push_back(i);
    }
    tot = 0;
    dfs(1);
    int a;
    for(int i = 1;i<=n;i++)
    {
      cin>>a;
      shu[path[i][1]] = a;
    }
    build(1,1,n);
    int m;
    cin>>m;
    while(m--)
    {
      int quan;
      char s[10];
      cin>>s>>quan;
      if(s[0] == 'g')
      {
        cout<<query(1,path[quan][0],path[quan][1])<<endl;
      }
      else
      {
        duan_up(1,path[quan][0],path[quan][1],1);
      }
    }
  }
  return 0;
}
