#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<iostream>
using  namespace std;

int main()
{
    int w,m;
    int flag=1;
    while(cin>>w>>m)
    {
       while(m)
       {
           if(m%w==0 || m %w ==1)
           {
               m=m/w;
           }
           else if(m%w == w-1)
           {
               m=(m+1)/w;
           }
           else
           {
               printf("NO\n");
               break;
           }
       }
       if(!m) printf("YES\n");
    }
    return 0;
}
