#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int gcd(int a , int b)
{
    int i=min(a,b);
    for(;i>1;i--)
    {
        if(a%i==0 && b%i==0) break;
    }
    return i;
}
int main()
{
     int a,b;
     while(scanf("%d%d",&a,&b)==2)
     {
         int t=b,k=0,s=1;
         while(t-- && k!=1)
         {
             k=gcd(a,b);
             a/=k;
             s*=k;
         }
         printf("%d\n",s);
     }
    return 0;
}
