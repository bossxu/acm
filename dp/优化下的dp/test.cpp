#include<bits/stdc++.h>
#define LL long long
using namespace std;
int p,n,l,head,tail;
int c[50003],q[50003];
LL f[50003],g[50003],sum[50003];
LL Get(int i,int j)
{
    return f[i]-f[j]+g[i]*g[i]-g[j]*g[j]+2*p*(g[i]-g[j]);
}
main()
{
    scanf("%d%d",&n,&l);
    for (int i=1;i<=n;i++)
        scanf("%d",c+i),
        sum[i]=sum[i-1]+c[i],
        g[i]=sum[i]+i;
    p=l+1;
    head=tail=1;
    for (int i=1;i<=n;i++)
    {
        cout<<g[i]<<endl;
        while (head<tail&&Get(q[head+1],q[head])<2*g[i]*(g[q[head+1]]-g[q[head]])) head++;
        f[i]=f[q[head]]+(g[i]-g[q[head]]-p)*(g[i]-g[q[head]]-p);
        while (head<tail&&Get(q[tail],q[tail-1])*(g[i]-g[q[tail]])>Get(i,q[tail])*(g[q[tail]]-g[q[tail-1]])) tail--;
        q[++tail]=i;
    }
    printf("%lld",f[n]);
}
