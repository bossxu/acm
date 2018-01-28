#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using  namespace std;
long long ans;
long long moving(int k,int *s,int fin)
{
    if(k==0) return 0;
    if(s[k]== fin) return moving(k-1,s,fin);//刚好匹配的话那么这个就不要动
    return moving(k-1,s,6-fin-s[k]) +(1LL<<(k-1))//这一个就是简单汉罗塔的复杂度 ;
}
int main()
{
    int shu=0;
    int st[61],en[61];
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        int i;ans=0;
        for(i=1;i<=n;i++) cin>>st[i];
        for(i=1;i<=n;i++) cin>>en[i];
        int k=n;
        while(k>=1 && st[k]==en[k]) k--;
        int o=6-st[k]-en[k];
        if(k>=1)
        {
            ans=moving(k-1,st,o) + moving(k-1,en,o)+1 //我先找到需要转移的最大的那个，它想要转移的条件就是把前 面都转移到一个没有用的棒子上;
        }
        printf("Case %d: %lld\n",++shu,ans);
    }
}
