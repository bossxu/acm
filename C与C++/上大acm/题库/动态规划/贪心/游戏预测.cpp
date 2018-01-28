#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int s[52];
    int m,n,i,cou,big,k,madan=0;
    while(scanf("%d%d",&m,&n)==2)
    {
        cou=0;big=0;
        if(m==0 && n==0 ) break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        sort(s,s+n);
        i=n-1;k=m*n;
         while( i>=0)
         {
             if(s[i]==k)
             {
                 cou++;
                 if(big<cou) big=cou;
                 i--;
             }
             else
             {
                 cou--;
             }
            k--;
         }
        printf("Case %d: %d\n",++madan,big);
    }
    return 0;
}


