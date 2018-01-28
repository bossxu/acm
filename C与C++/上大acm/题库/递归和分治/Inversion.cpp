#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using  namespace std;

struct stu
{
    int idea;
    int big;
}node[100005];
int cmp(stu a, stu b)
{
    if(a.big<b.big) return 1;
    else return 0;
}
int main()
{
    int n;
    long long k;
    while(scanf("%d%lld",&n,&k)==2)
    {
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&node[i].big);
            node[i].idea=i;
        }
        sort(node,node+n,cmp);
        long long c=0;
        for(i=0;i<n;i++)
        {
            if(i-node[i].idea>0) c-=node[i].idea-i;
        }
        printf("%lld\n",c-k);
    }
return 0;
}
