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
//线段树 点的更新 区间最大
int n,m;
int score[200005];
struct Node{  
    int l,r,maxn;  
}tree[1000000];  
  
void Build(int t,int l,int r){  
    tree[t].l = l;  
    tree[t].r = r;  
    int mid = (l + r) / 2;  
    if(l == r){  
        tree[t].maxn = score[mid];  
        return;  
    }  
    Build(2*t,l,mid);  
    Build(2*t+1,mid+1,r);  
    tree[t].maxn = max(tree[2*t].maxn,tree[2*t+1].maxn);  
}  
  
int Query(int t,int x,int y){  
    int l = tree[t].l;  
    int r = tree[t].r;  
    if(l == x && r == y)  
        return tree[t].maxn;  
    int mid = (l + r) / 2;  
    if(x <= mid && y <= mid)    return Query(2*t,x,y);
    else if(x > mid)    return Query(2*t+1,x,y);  
    else return max(Query(2*t,x,mid),Query(2*t+1,mid+1,y));  
}  
  
void Modify(int t,int x,int der){  
    int l,r,mid;  
    l = tree[t].l;  
    r = tree[t].r;  
    mid = (l + r) / 2;  
    if(l == r){  
        tree[t].maxn = der;  
        return;  
    }  
    if(x <= mid)   Modify(2*t,x,der);  
    else    Modify(2*t+1,x,der);  
    tree[t].maxn = max(Query(2*t,l,mid),Query(2*t+1,mid+1,r));
}
int main()
{
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&score[i]);
        }
        char c;
        int x,y;
        Build(1,1,n);
        while(m--)
        {
            cin>>c>>x>>y;
            if(c=='Q')
            {
                if(x>y)
                {
                    int t;
                    t=y;y=x;x=t;
                }
                int k= Query(1,x,y);
                printf("%d\n",k);
                continue;
            }
            if(c=='U')
            {
               Modify(1,x,y);
                continue;
            }
        }
    }
    return 0;
}