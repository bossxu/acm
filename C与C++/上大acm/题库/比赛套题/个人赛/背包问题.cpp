#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct stz
{
   int a,b,l;
}node[1005];
int cmp_1(stz z,stz c)
{
    if(z.b>c.b) return 1;
    else if(z.b==c.b && z.a<c.a ) return 1;
    else return 0;
}
int cmp_2(stz z,stz c)
{
    if(c.l>z.l)
    return 0;
    else return 1;
}
int cmp_3(stz z,stz c)
{
    if(z.a<c.b) return 1;
    if(z.a==c.a && z.b > c.b) return 1;
    return 0;
}
int main()
{
   int T,V,N;

   cin>>T;
   while(T--)
   {
     scanf("%d%d",&V,&N);
     int i,flag=0;
     for(i=0;i<N;i++)
     {

         scanf("%d%d",&node[i].a,&node[i].b);
         node[i].l=node[i].b-node[i].a;
     }
         sort(node,node+N,cmp_1);int k=V;
         for(i=0;i<=N;i++)
         {
             if(i==N)
             {
                 flag=1;break;
             }
               if(k>=node[i].b)
               k=k-node[i].a;
               else
               break;
         }
         sort(node,node+N,cmp_2);k=V;
         for(i=0;i<=N;i++)
         {
             if(i==N)
             {
                 flag=1;break;
             }
               if(k>=node[i].b)
               k=k-node[i].a;
               else
               break;
         }
         sort(node,node+N,cmp_3);k=V;
         for(i=0;i<=N;i++)
         {
             if(i==N)
             {
                 flag=1;break;
             }
               if(k>=node[i].b)
               k=k-node[i].a;
               else
               break;
         }

         if(flag == 1) printf("Yes\n");
         else printf("No\n");
     }
   return 0;
}
