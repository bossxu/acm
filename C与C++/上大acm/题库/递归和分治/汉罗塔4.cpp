#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<iostream>
using  namespace std;
long long dp[30];

int main()
{
    dp[1]=3;
    int i;
    for(i=2;i<30;i++)
    {
        dp[i]=dp[i-1]*3;
    }
    int T;
    while(scanf("%d",&T)==1)
    {
        printf("%lld\n",dp[T]);
    }
    return 0;
}
