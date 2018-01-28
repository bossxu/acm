#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int it;
struct st 
{
   char l,r;

}node[100];
int cou[100];
void dfs(char c, int n)
{
   int i =0; 
   for(i=1;i<n;i++)
   {
       if(cou[i]==0) continue;
       if(node[i].l==c) 
       {
           if( node [i].r=='m')
           {
               it = 1;
               return ;
           }
           else
           {
               cou[i]=0;
               dfs(node[i].r,n);
           }
       }
   }
   
}
int main()
{
   int  i=0;
   char c[100];
   memset(cou,1,sizeof(cou));
   while(scanf("%s",c)!=EOF)
   {
      node[++i].l= c[0];
      node[i].r= c[strlen(c)-1];
      if(node[i].l == '0')
      {
         it =0;
         dfs('b',i);
         if(it== 1) printf("Yes.\n");
         else printf("No.\n"); 
         memset(cou,0,sizeof(cou));
         i=0;
      } 
   } 
   return 0;
}