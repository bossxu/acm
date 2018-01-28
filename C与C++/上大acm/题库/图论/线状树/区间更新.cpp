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
#include<map>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
    const int maxn = 100005;
// 知识点分解：区间更新
int tag[maxn*4];
void pushdown(int t,int m);
// lazy 数组表示要不要更新 tag数组表示那个区间的数到底怎么更新
/*
  lazy 思想在于我在这个地方要不要向底层更新
  tag  意思在于记录是怎么变化
  HDU 1698
  这才是属于自己的模版
*/
struct Treenode{
    int l,r;
    int sum=0;
}node[maxn*4];
void build(int t, int le, int ri)//建树
{
    node[t].l=le;
    node[t].r=ri;
    tag[t]=0;
    if(le==ri)
    {
      node[t].sum=1;
      return;
    }
    int mid=(le+ri)>>1;
    build(t*2,le,mid);
    build(t*2+1,mid+1,ri);
    node[t].sum=node[t*2].sum+node[t*2+1].sum;
}
void update(int t,int le,int ri,int c)
{
   int L=node[t].l;
   int R=node[t].r;
   if(le==L && ri == R)
   {
      tag[t]=c;
      node[t].sum = (R-L+1)*c;
      return ;
   }
   if(L==R) return ;
   pushdown(t,R-L+1);
   int mid = (L+R)/2;
   if(ri<=mid) update(t<<1,le,ri,c);
   else if(le>mid) update(t<<1|1,le,ri,c);
   else//
   {
    update(t<<1,le,mid,c);
    update(t<<1|1,mid+1,ri,c);
   }
   node[t].sum=node[t*2].sum+node[t*2+1].sum;
}
void pushdown(int t,int m)//此处的目的在于更新节点，向底层更新
{
    if(tag[t])
    {
        tag[t<<1]=tag[t];
        tag[t<<1|1]=tag[t];
        node[t<<1].sum = tag[t]*(m-(m>>1));
        node[t<<1|1].sum = tag[t]*(m>>1);
        tag[t]=0;
    }
}
int query(int t,int l, int r)
{
    int L=node[t].l;
    int R=node[t].r;
    if(l==L && r==R)
    {
        return node[t].sum;
    }
    pushdown(t,R-L+1);
    int mid = (L+R)>>1;
    int ans=0;
    if(r<=mid)
    {
        ans+=query(t<<1,l,r);
    }
    else if(l>mid)
    {
        ans+=query(t<<1|1,l,r);
    }
    else
    {
        ans+=query(t<<1,l,mid);
        ans+=query(t<<1|1,mid+1,r);
    }
   return ans;
}
int main()
{
    int n,m,t;
    cin>>t;
    int co=0;
    while(t--)
    {
        cin>>n>>m;
        build(1,1,n);
        while(m--)
        {
          int a,b,c;
          cin>>a>>b>>c;
          if(a>b)
          {
              int t;
              t=a,a=b,b=t;
          }
          update(1,a,b,c);
        }
        printf("Case %d: The total value of the hook is %d.\n",++co,query(1,1,n));
    }
    return 0;
}