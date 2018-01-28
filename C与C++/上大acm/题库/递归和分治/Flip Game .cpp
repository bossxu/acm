#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using  namespace std;
int shu[100005];
int n,m;
int l,r;
int erfen(int l,int r)
{
    int mid =
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
     int i,big=0;
     long long sum=0;
     for(i=1;i<=m;i++)
     {
         cin>>shu[i];
         sum+=shu[i];
         if(shu[i]>big) big=shu[i];
     }
     l=big;
     r=sum;
     mid=(l+r)/2;
     while(l<r)
        {
            if()
        }
    }
    return 0;
}
