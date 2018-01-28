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
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
const int maxn = 100005;
void pushdown(int t, int m);
// 知识点分解：区间更新
struct Treenode{
    int l,r;
    int sum;
}node[maxn*4];
int tag[maxn*4];
void build(int t, int le, int ri)//建树
{
    node[t].l=le;
    node[t].r=ri;
    tag[t]=0;
    if(le==ri)
    {
      node[t].sum=0;
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
      tag[t]+=c;
      node[t].sum += (R-L+1)*c;
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
        tag[t<<1]+=tag[t];
        tag[t<<1|1]+=tag[t];
        node[t<<1].sum += tag[t]*(m-(m>>1));
        node[t<<1|1].sum += tag[t]*(m>>1);
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
    int n;
    while(scanf("%d",&n) && n)
    {
        build(1,1,n);
      for(int i=1;i<=n;i++)
      {
          int a,b;
          cin>>a>>b;
          update(1,a,b,1);
      }
       int a=0; cout<<query(1,1,1)<<" ";
       for(int i=2;i<n;i++)
       {
          a=query(1,1,i)-query(1,1,i-1);
          cout<<a<<" ";
       }
       cout<<query(1,1,n)-query(1,1,n-1)<<endl;
    }

    return 0;
}