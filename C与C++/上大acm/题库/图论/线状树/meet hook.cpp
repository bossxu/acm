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
#define lowbit(x) (x&-x)
const double eps = 1e-6;
int n;
const int MAXN=100010;
//知识点 ，区间更新，邝斌模版
struct Node
{
    int l,r;
    int lazy,tag;
    int sum;
}segTree[MAXN*3];//tag 值 lazy 一个标记数组 sum 区间的和
void Build(int i,int l,int r)
{
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].lazy=0;
    segTree[i].tag=0;
    if(l==r)
    {
        segTree[i].sum=1;
        return;
    }
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build((i<<1)|1,mid+1,r);
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}
void update(int i,int l,int r,int v)// i 跟点 l 区间左端 r 区间右端
{
    if(segTree[i].l==l&&segTree[i].r==r)//成段更新
    {
        segTree[i].lazy=1;
        segTree[i].tag=v;
        segTree[i].sum=(r-l+1)*v;
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(segTree[i].lazy==1)//
    {
        segTree[i].lazy=0;
        update(i<<1,segTree[i].l,mid,segTree[i].tag);
        update((i<<1)|1,mid+1,segTree[i].r,segTree[i].tag);
        segTree[i].tag=0;
    }
    if(r<=mid) update(i<<1,l,r,v);
    else if(l>mid)update((i<<1)|1,l,r,v);
    else
    {
        update(i<<1,l,mid,v);
        update((i<<1)|1,mid+1,r,v);
    }
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}
int main()
{
    int t;
    int co=0;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>n>>q;
        Build(1,1,n);
        while(q--)
        {
            int x,y,c;
            cin>>x>>y>>c;
            update(1,x,y,c);
        }
        printf("Case %d: The total value of the hook is %d.\n",++co,segTree[1].sum);
       
    }
    system("pause");
    return 0;
}