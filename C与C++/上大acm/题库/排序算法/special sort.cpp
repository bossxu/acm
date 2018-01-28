#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

struct st{
    ll x,y;
    int item;
    ll sum;
    int o;
}node[10005];
int cmp(st a, st b)
{
   if(a.sum>b.sum) return 1;
   if(a.sum==b.sum)
    {if(a.item>b.item) return 1;
     if(a.item==b.item)
        if(a.o<b.o) return 1;
    }
    return 0;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        ll a,b;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld",&a,&b);
            node[i].x=a,node[i].y=b,node[i].sum=a+b;
            if(a<b) node[i].item=1;
            if(a==b) node[i].item=2;
            if(a>b) node[i].item=3;
            node[i].o=i;
        }
        sort(node,node+n,cmp);
        for(int i=0;i<n;i++)
        {
          printf("%lld+%lld=[%c%lld]\n",node[i].x,node[i].y,node[i].item+59,node[i].sum);
        }
        putchar('\n');
    }
    return 0;
}