#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct st
{
  int h,g;
  float b; 
}node[10005];
int cmp(st a,st z)
{
    if(a.b>z.b) return 1;
    return 0;
}
int chu(int a,int b)
{
  int c=a/b;
  if(c*b<a) return c+1;
  else return c;
}
int main()
{
   int T,cnt=0;
   cin>>T; 
   int n,m;
   while(T--)
   {
       scanf("%d%d",&n,&m);
       int i,j,s=0;
       for(i=0;i<n;i++)
       {
         scanf("%d%d",&node[i].h,&node[i].g);
         node[i].b = 1.0 * node[i].g/chu(node[i].h,m);
         s+=node[i].g;
       }
       sort(node,node+n,cmp);
      //for(i=0;i<n;i++) printf("%f\n",node[i].b);
       ll sum=0;
       for(i=0;i<n;i++)
       {
          j = node[i].h/m;
          if(j*m<node[i].h) sum+=s*(j+1);
          else sum+=s*(j);
          s-=node[i].g; 
         // printf("%d  %d \n",s,sum);
       }
     printf("Case #%d: %lld\n",++cnt,sum);
   }
     return 0;
}