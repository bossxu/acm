#include<bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
typedef long long ll;
const int maxn=1e5+10;
int mo[maxn];
ll sum[maxn*4];
bool flag[maxn*4];
int cnt[maxn*4];
int b[maxn];
int N,Q;
char op[10];
int u,v;
void pushdown(int rt)
{
    if(cnt[rt])
    {
        cnt[lson]+=cnt[rt];
        cnt[rson]+=cnt[rt];
        cnt[rt]=0;
    }
    if(flag[rt])
    {
        flag[lson]=true;
        flag[rson]=true;
    }
}
void pushup(int rt)
{
    sum[rt]=sum[lson]+sum[rson];
}
void update(int l,int r,int L,int R,int rt)
{
    flag[rt]=true;
    if(l<=L&&r>=R)
    {
        cnt[rt]++;
        return ;
    }
    int mid=(L+R)>>1;
    if(l<=mid)
        update(l,r,Lson);
    if(r>mid)
        update(l,r,Rson);
    //]pushup(rt);
}
ll query(int l,int r,int L,int R,int rt)
{
    if(L==R)
    {
        mo[L]+=cnt[rt];
        sum[rt]+=mo[L]/b[L];
        mo[L]%=b[L];
        cnt[rt]=0;
        flag[rt]=false;
        return sum[rt];
    }
    //pushdown(rt);
    if(l<=L && r>=R)
    {
        if(!flag[rt])
        {
            return sum[rt];
        }
    }
    //flag[rt]=false;
    pushdown(rt);
    int mid=(L+R)>>1;
    ll res=0;
    if(l<=mid)
        res+=query(l,r,Lson);
    if(r>mid)
        res+=query(l,r,Rson);
    pushup(rt);
    return res;
}
int main()
{
    while(scanf("%d%d",&N,&Q)!=EOF)
    {
        for(int i=1;i<=N;i++)
            scanf("%d",&b[i]);
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        while(Q--)
        {
            scanf("%s%d%d",op,&u,&v);
            if(op[0]=='a')
            {
                update(u,v,1,N,1);
            }
            else
            {
                printf("%lld\n",query(u,v,1,N,1));
            }
        }
    }
    return 0;
}
