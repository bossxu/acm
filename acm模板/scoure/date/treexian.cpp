#define lson rt<<1
#define rson rt<<1|1
//单点更新模板题
const int maxn = 50005;
ll a[maxn];
struct node
{
  int l,r;
  ll sum;
}tree[maxn<<2];
void build(int rt, int l, int r)//建树
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].sum = a[l];
    return ;
  }
  int mid = (l+r)>>1;
  build(lson,l,mid);
  build(rson,mid+1,r);
  tree[rt].sum = tree[lson].sum+tree[rson].sum;
}
void update_dian(int rt,int a,int val)
{
  if(tree[rt].l == a && tree[rt].r == a)
  {
    tree[rt].sum += val;
    return;
  }
  int mid = (tree[rt].l+tree[rt].r)>>1;
  if(a<=mid) update_dian(lson,a,val);
  else update_dian(rson,a,val);
  tree[rt].sum = tree[lson].sum+tree[rson].sum;
}

ll query(int rt,int l,int r)
{
//  cout<<l<<"  "<<r<<endl;
  if(l == tree[rt].l && r == tree[rt].r) return tree[rt].sum;
  int mid = (tree[rt].l+tree[rt].r)/2;
  if(r <= mid)  return query(lson,l,r);
  if(l>mid)    return query(rson,l,r);
  return query(lson,l,mid) + query(rson,mid+1,r);
}
//区间加模板
int lazy[maxn<<2];
struct node
{
  int l,r;
  int s;
}tree[maxn<<2];
void pushup(int rt)
{
  tree[rt].s = tree[lson].s+tree[rson].s;
}
void pushdown(int rt ,int len)
{
  if(lazy[rt]!=0)
  {
    lazy[lson] += lazy[rt];
    lazy[rson] += lazy[rt];
    tree[lson].s += lazy[rt]*(len-(len>>1));
    tree[rson].s += lazy[rt]*(len>>1);
    lazy[rt] = 0;
  }
}
void build(int rt, int l, int r)//建树
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].s = a[l];
    return ;
  }
  int mid = (l+r)>>1;
  build(lson,l,mid);
  build(rson,mid+1,r);
  pushup(rt);
}
void duan_up(int rt,int l,int r,ll m)
{
  if(tree[rt].l>=l && tree[rt].r<=r)
  {
    lazy[rt] += m;
    tree[rt].s += m*(tree[rt].r-tree[rt].l+1);
    return;
  }
  pushdown(rt,tree[rt].r-tree[rt].l+1);
  int mid = (tree[rt].l+tree[rt].r)>>1;
  if(l<=mid) duan_up(lson,l,r,m);
  if(r>mid) duan_up(rson,l,r,m);
  pushup(rt);
}
ll query(int rt,int l,int r)
{
  if(l <= tree[rt].l && r >= tree[rt].r) return tree[rt].s;
  pushdown(rt,tree[rt].r-tree[rt].l+1);
  int mid = (tree[rt].l+tree[rt].r)/2;
  ll ans= 0;
  if(l <= mid)  ans+= query(lson,l,r);
  if(r>mid)    ans+= query(rson,l,r);
  return ans;
}
//区间变
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
  if(l <= tree[rt].l && r >= tree[rt].r) return tree[rt].s;
  pushdown(rt,tree[rt].r-tree[rt].l+1);
  int mid = (tree[rt].l+tree[rt].r)/2;
  int ans= 0;
  if(l <= mid)  ans+= query(lson,l,r);
  if(r>mid)    ans+= query(rson,l,r);
  return ans;
}
