#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<iostream>
using  namespace std;
long long ret(int n, int k)
{
    long long c=1;int i;
    for(i=1;i<=n-k;i++)
        c*=2;
    return c;
}
int main()
{
    int n,k;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        printf("%lld\n",ret(n,k));
    }
    return 0;
}


