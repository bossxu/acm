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
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int n,m;
int score[1<<18];
struct Node{
    int max1,min1;
    int l,r;
}tree[1<<18];

void Build(int t,int l,int r){
    tree[t].l = l;
    tree[t].r = r;
    int mid = (l + r) / 2;
    if(l == r){
        tree[t].max1 = score[mid];
        tree[t].min1 = score[mid];
        return;
    }
    Build(2*t,l,mid);
    Build(2*t+1,mid+1,r);
    tree[t].max1 = max(tree[2*t].max1,tree[2*t+1].max1);
    tree[t].min1 = min(tree[2*t].min1,tree[2*t+1].min1);

}
ll Querymax(int t,int x,int y){
    int l = tree[t].l;
    int r = tree[t].r;
    if(l == x && r == y)
        {
        return tree[t].max1;
        }
    int mid = (l + r) / 2;
    if(x <= mid && y <= mid)    return Querymax(2*t,x,y);
    else if(x > mid)    return Querymax(2*t+1,x,y);
    else return max(Querymax(2*t,x,mid),Querymax(2*t+1,mid+1,y));
}
ll Querymin(int t,int x,int y){
    int l = tree[t].l;
    int r = tree[t].r;
    if(l == x && r == y)
        {
        return tree[t].min1;
        }
    int mid = (l + r) / 2;
    if(x <= mid && y <= mid)    return Querymin(2*t,x,y);
    else if(x > mid)    return Querymin(2*t+1,x,y);
    else return min(Querymin(2*t,x,mid),Querymin(2*t+1,mid+1,y));
}

void Modify(int t,int x,int der){
    int l,r,mid;
    l = tree[t].l;
    r = tree[t].r;
    mid = (l + r) / 2;
    if(l == r){
        tree[t].min1 = der;
        tree[t].max1 = der;
        return;
    }
    if(x <= mid)   Modify(2*t,x,der);
    else    Modify(2*t+1,x,der);
    tree[t].max1 = max(tree[2*t].max1,tree[2*t+1].max1);
    tree[t].min1 = min(tree[2*t].min1,tree[2*t+1].min1);

}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t ;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    clr(score,0);
    for(int i =0;i<1<<n;i++)
    {
      scanf("%d",&score[i]);
    }
    Build(1,0,(1<<n)-1);
    int q;
    cin>>q;
    while(q--)
    {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      if(a==1)
      {
        ll f = Querymin(1,b,c);
        ll l = Querymax(1,b,c);
        if(l<=0) cout<<l*l<<endl;
        else if(f<0) cout<<f*l<<endl;
        else cout<<f*f<<endl;
      }
      else
      {
        Modify(1,b,c);
      }
    }
  }

  return 0;
}
