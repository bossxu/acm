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
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
#define lson rt<<1
#define rson rt<<1|1
const int maxn = 200005;
ll a[maxn];
struct node
{
  int l,r;
  int big;
}tree[maxn<<2];
void build(int rt, int l, int r)//建树
{
  tree[rt].l = l;
  tree[rt].r = r;
  if(l == r)
  {
    tree[rt].big = a[l];
    return ;
  }
  int mid = (l+r)>>1;
  build(lson,l,mid);
  build(rson,mid+1,r);
  tree[rt].big = max(tree[lson].big,tree[rson].big);
}
void update_dian(int rt,int a,int val)
{
  if(tree[rt].l == a && tree[rt].r == a)
  {
    tree[rt].big = val;
    return;
  }
  int mid = (tree[rt].l+tree[rt].r)>>1;
  if(a<=mid) update_dian(lson,a,val);
  else update_dian(rson,a,val);
  tree[rt].big = max(tree[lson].big,tree[rson].big);
}
ll query(int rt,int l,int r)
{
//  cout<<l<<"  "<<r<<endl;
  if(l == tree[rt].l && r == tree[rt].r) return tree[rt].big;
  int mid = (tree[rt].l+tree[rt].r)/2;
  if(r <= mid)  return query(lson,l,r);
  if(l>mid)    return query(rson,l,r);
  return max(query(lson,l,mid),query(rson,mid+1,r));
}
int main()
{
  //why it happen
   std::ios::sync_with_stdio(false);
   int n;
   int m;
   while(cin>>n>>m)
   {
     for(int i = 1;i<=n;i++)
     {
       cin>>a[i];
     }
     build(1,1,n);
     char c;
     int d,b;
     for(int i = 1;i<=m;i++)
     {
       cin>>c>>d>>b;
       if(c == 'Q')
        cout<<query(1,d,b)<<endl;
       if(c == 'U')
         update_dian(1,d,b);
     }
   }
  return 0;
}
