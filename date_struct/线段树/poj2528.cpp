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
const int maxn = 20005;
#define lson rt<<1
#define rson rt<<1|1
//区间加,离散化
int a[maxn<<2];
int lazy[maxn];
int vis[maxn];
struct ko
{
  int l,r;
}no[maxn];
struct node
{
  int l,r;
  int s;
}tree[maxn<<2];
void pushdown(int rt)
{
  if(tree[rt].s)
  {
    tree[lson].s = tree[rson].s = tree[rt].s;
    tree[rt].s = 0;
  }
}
void build(int rt, int l, int r)//建树
{
  tree[rt].l = l;
  tree[rt].r = r;
  tree[rt].s = 0;
  if(l == r)
  {
    return ;
  }
  int mid = (l+r)>>1;
  build(lson,l,mid);
  build(rson,mid+1,r);
}
void duan_up(int rt,int l,int r,int m)
{
  //cout<<tree[rt].l<<"  "<<tree[rt].r<<" "<<tree[rt].s<<endl;
  if(tree[rt].l>=l && tree[rt].r<=r)
  {
    tree[rt].s = m;
    return;
  }
  if(tree[rt].s)
  pushdown(rt);
  int mid = (tree[rt].l+tree[rt].r)>>1;
  if(l<=mid) duan_up(lson,l,r,m);
  if(r>mid) duan_up(rson,l,r,m);
}
int ans;
void query(int rt)
{
  //cout<<l<<"  "<<r<<endl;
  if(tree[rt].l == tree[rt].r)
  {
    //cout<<tree[rt].s<<endl;
    if(tree[rt].s)
  {
    if(!vis[tree[rt].s])
    {
      ans++;
      vis[tree[rt].s] = 1;
    }
  }
  return;
  }
  if(tree[rt].s) pushdown(rt);
  query(lson);
  query(rson);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  int n;
  while(t--)
  {
    cin>>n;
    clr(vis,0);
    for(int i = 1;i<=n;i++)
    {
      cin>>no[i].l>>no[i].r;
      a[i] = no[i].l;
      a[i+n] = no[i].r;
    }
    sort(a+1,a+2*n+1);
    int item = 1;
    int flag = 1;
    while(flag<=2*n)
    {
      a[item++] = a[flag];
      while(a[flag] == a[item-1]) flag++;
    }
    item--;
    build(1,1,item);
    //clr(lazy,0);
    for(int i = 1;i<=n;i++)
    {
      no[i].l = lower_bound(a+1,a+item+1,no[i].l) - a;
      no[i].r = lower_bound(a+1,a+item+1,no[i].r) - a;
      duan_up(1,no[i].l,no[i].r,i);
    }
    ans = 0;
    query(1);
    cout<<ans<<endl;
  }

  return 0;
}
