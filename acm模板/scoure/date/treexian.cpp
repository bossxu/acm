
long long int node[mod];//注意数据大小，小心爆了，本渣渣就爆了好久
void build(int l,int r,int root,int n)
{
    int mid;
    if(l==r)
    {
        scanf("%lld",&node[root]);
        return;
    }
    mid=(l+r)>>1;
    build(l,mid,root<<1,n);
    build(mid+1,r,root<<1|1,n);
}
void update(int L,int R,long long int add,int l,int r,int root)
{
    if(L<=l && R>=r)
    {
        node[root]+=add;
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) update(L,R,add,l,mid,root<<1);
    if(mid<R) update(L,R,add,mid+1,r,root<<1|1);
}
void query(int l,int r,int root,long long int k)
{
    if(l==r)
    {
        if(l==1)printf("%lld",node[root]+k) ;
        else printf(" %lld",node[root]+k) ;
        return ;
    }
    int mid=(l+r)>>1;
    query(l,mid,root<<1,k+node[root]);
    query(mid+1,r,root<<1|1,k+node[root]);
}
