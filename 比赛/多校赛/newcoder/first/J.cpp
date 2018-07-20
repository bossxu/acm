#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
struct node
{
  int l,r,id;
  bool operator< (node t) const
  {
    return r<t.r;
  }
}q[maxn];
int bit[maxn];
int ans[maxn];
int pos[maxn];
int sum(int i)
{
  int res=0;
  while(i>0)
  {
    res+=bit[i];
    i-=i&-i;
  }
  return res;
}
void add(int i,int x)
{
  while(i<maxn)
  {
    bit[i]+=x;
    i+=i&-i;
  }
}
void init()
{
  memset(pos,0,sizeof(pos));
  memset(bit,0,sizeof(bit));
}
int main()
{
  int N,Q;
  while(scanf("%d%d",&N,&Q)!=EOF)
  {
    init();
    for(int i=1;i<=N;i++)
    {
      scanf("%d",&a[i]);
      a[i+N]=a[i];
    }
    for(int i=0;i<Q;i++)
    {
      scanf("%d%d",&q[i].r,&q[i].l);
      q[i].id=i;
      q[i].r+=N;
    }
    sort(q,q+Q);
    int pre=1;
    for(int i=0;i<Q;i++)
    {
      for(int j=pre;j<=q[i].r;j++)
      {
        if(pos[a[j]]!=0)
        {
          add(pos[a[j]],-1);
        }
        add(j,1);
        pos[a[j]]=j;
      }
      pre=q[i].r+1;
      ans[q[i].id]=sum(q[i].r)-sum(q[i].l-1);
    }
    for(int i=0;i<Q;i++)
    {
      //printf("%d %d\n",q[i].l,q[i].r);
      printf("%d\n",ans[i]);
    }
  }
  return 0;
}
