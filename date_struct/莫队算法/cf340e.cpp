#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 1<<20;
//莫对经典算法例题

struct node
{
  int l,r,id;
}Q[N];
ll ans[N],flag[N];
int a[N],pos[N];
int n,m,k;
int L = 1,R = 0;
ll num = 0;
bool cmp(node a,node b)
{
  if(pos[a.l] == pos[b.l])
  {
    return a.r<b.r;
  }
  return pos[a.l]<pos[b.l];
}
void add(int x)
{
  num += flag[a[x]^k];
  flag[a[x]]++;
}
void del(int x)
{
  flag[a[x]]--;
  num -= flag[a[x]^k];
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  cin>>n>>m>>k;
  int sz = sqrt(n);
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
    a[i]^=a[i-1];
    pos[i] = i/sz;
  }
  for(int i = 1;i<=m;i++)
  {
    cin>>Q[i].l>>Q[i].r;
    Q[i].id = i;
  }
  sort(Q+1,Q+m+1,cmp);
  flag[0] = 1;
  for(int i = 1;i<=m;i++)
  {
    while(L<Q[i].l)
    {
      del(L-1);
      L++;
    }
    while(L>Q[i].l)
    {
      L--;
      add(L-1);
    }
    while(R<Q[i].r)
    {
      R++;
      add(R);
    }
    while(R>Q[i].r)
    {
      del(R);
      R--;
    }
    ans[Q[i].id]  = num;
  }
  for(int i = 1;i<=m;i++)
  {
    cout<<ans[i]<<endl;
  }
  return 0;
}
