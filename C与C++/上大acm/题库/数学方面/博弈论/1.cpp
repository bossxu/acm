#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
       if(n>=3) printf("Bob\n");
       else printf("Alice\n") ;
    }
    return 0;
}