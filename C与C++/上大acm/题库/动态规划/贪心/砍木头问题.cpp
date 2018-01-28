#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
    int len,wei;
}node[5005];
int cmp(point a, point b)
{
    if(a.len>b.len) return 0;
    else return 1;
}
int main()
{
   int t,n;
   int c[5005];
   cin>>t;
   int i,cou=0;
    int j,k;
   while(t--)
   {
        cou=0;
       scanf("%d",&n);
       memset(c,1,sizeof(c));
     for(i=0;i<n;i++)
       {
           scanf("%d%d",&node[i].len,&node[i].wei);
       }
       sort(node,node+n,cmp);
       i=0;
       while(i<n)
       {
           c[i]=0;
           for(j=i+1;j<n;j++)
           {
               while(c[j]==0 && j<n) j++;
               if(node[i].wei<=node[j].wei)
               {
                   i=j;
                   c[j]=0;
               }
           }
           i=0;
           while(!c[i] && i<=n) i++;
           cou++;
       }
         printf("%d\n",cou);
   }
    return 0;
}

