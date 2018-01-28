#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct st{
    int xue;
    char name[55];
    int num;
}node[303];
int cmp(st a, st b)
{
    if(a.num>b.num) return 1;
    if(a.num == b.num) 
     if(a.xue<b.xue) return 1;
     return 0;
}
int main()
{
   int n,b;
   char a[55];
   while(scanf("%d",&n)==1)
   {
      for(int i=0;i<n;i++)
      {
          scanf("%s%d",node[i].name,&node[i].num);
          node[i].xue=i+1;
      } 
      sort(node,node+n,cmp);
      int m = INF,item =0,error=0;
      for(int i=0;i<n;i++)
      {
          
         scanf("%s%d",a,&b);
         if(strcmp(a,node[i].name)!=0) item=1;
         if(m < b) 
         {
             error=1;
         }
         m=b;
      }
      if(error) printf("Error\n");
      else if(item) printf("Not Stable\n");
      else printf("Right\n");
      if(item || error)
      {
          for(int i=0;i<n;i++)
          {
              printf("%s %d\n",node[i].name,node[i].num);
          }
      }
   }
    return 0;
}