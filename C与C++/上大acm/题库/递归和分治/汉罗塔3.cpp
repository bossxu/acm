#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<iostream>
using  namespace std;
long long dp[36];
int main()
{
    int N,i;
    dp[1]=2;
    for(i=2;i<36;i++)
    {
        dp[i]=3*dp[i-1]+2;
    }
    while(scanf("%d",&N)==1)
    {
       printf("%lld\n",dp[N]);
    }

    return 0;
}
