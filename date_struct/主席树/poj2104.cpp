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
const int N = 100005;
struct Node
{
  int val;
  int id;
}shu[N];
int ran[N];
int cmp(Node a, Node b)
{
  return a.val<b.val;
}
struct node
{
  int l,r;
  int sum;
  node(){sum = 0;}
}tree[N*20];
int root[N];
int cnt;
void init()
{
  cnt = 1;
  root[0] = 0;
  tree[0].l = tree[0].r = tree[0].sum = 0;
}
void update(int num,int &rt,int l,int r)
{
  tree[cnt++] =  tree[rt];
  rt = cnt-1;
  tree[rt].sum++;
  if(l == r) return ;
  int mid = (l+r)>>1;
  if(num<=mid)
  {
    update(num,tree[rt].l,l,mid);
  }
  else
  {
    update(num,tree[rt].r,mid+1,r);
  }
}
int query(int i,int j,int k,int l,int r)
{
  int d = tree[tree[j].l].sum  - tree[tree[i].l].sum;
  if( l == r) return l;
  int mid = (l+r)>>1;
  if(k<=d) return query(tree[i].l , tree[j].l , k,l,mid);
  return query(tree[i].r,tree[j].r,k-d,mid+1,r);
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
   int n,m;
   while(cin>>n>>m)
   {
     for(int i = 1;i<=n;i++)
     {
       cin>>shu[i].val;
       shu[i].id = i;
     }
     sort(shu+1,shu+n+1,cmp);
     for(int i = 1;i<=n;i++)
     {
       ran[shu[i].id] = i;
     }
     init();
     for(int i = 1;i<=n;i++)
     {
       root[i] = root[i-1];
       update(ran[i],root[i],1,n);
     }
     int left,right,k;
     for(int i = 1;i<=m;i++)
     {
       cin>>left>>right>>k;
       cout<<shu[query(root[left-1],root[right],k,1,n)].val<<endl;
     }
   }
  return 0;
}
