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
  if(l == tree[rt].l && r == tree[rt].r) return tree[rt].sum;
  int mid = (tree[rt].l+tree[rt].r)/2;
  if(r <= mid)  return query(lson,l,r);
  if(l>=mid)    return query(rson,l,r);
  return query(lson,l,mid) + query(rson,mid+1,r);
}
char s[10];
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  int n;
  int flag = 0;
  while(t--)
  {
    cout<<"Case "<<(++flag)<<":"<<endl;
    for(int i = 1;i<=n;i++)
    {
      scanf("%lld",&a[i]);
    }
    build(1,1,n);
    while(true)
    {
      scanf("%s",s);
      cout<<s<<endl;
      if(s[0] == 'E') break;
      if(s[0] == 'Q')
      {
        int a,b;
        scanf("%d%d",&a,&b);
        cout<<query(1,a,b)<<endl;
      }
      if(s[0] == 'A')
      {
        int a,b;
        scanf("%d%d",&a,&b);
        update_dian(1,a,b);
      }
    }
  }
  return 0;
}
