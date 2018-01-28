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

struct per{
  int l;
  int h; 
  int he;
}node[2002];
int cmp(per a, per b)
{
  if(a.l>b.l) return 0;
  if(a.l==a.l)
  {
      if(a.h>b.h) return 0;
  }
  return 1;
}
int cmp_2(per a, per b)
{
  if(a.he>b.he) return 0;
  if(a.he==a.he)
  {
      if(a.h>b.h) return 0;
  }
  return 1;
}
int cmp_3(per a, per b)
{
  if(a.h>b.h) return 0;
  if(a.h==a.h)
  {
      if(a.l>b.l) return 0;
  }
  return 1;
}
int main()
{
  int n;
  while(scanf("%d",&n)==1)
  {
      int i,j,m=0,wa,sum=0,co_1=0,co_2=0,co_3=0;
      for(i=1;i<=n;i++)
      {
          scanf("%d%d",&node[i].h,&node[i].l);
          m=max(node[i].l+node[i].h,m);
          sum+=node[i].h;
          node[i].he = node[i].l+node[i].h ;
      }
      scanf("%d",&wa);
      if(m>=wa) printf("%d\n",n);
      else
     {
      sort(node+1,node+n+1,cmp);
      for(i=1;i<=n;i++)
      {
         if(sum+node[i].l >= wa) 
         {
             sum-=node[i].h;
             co_1++;
         }  
      }
      sort(node+1,node+n+1,cmp_2);
          for(i=1;i<=n;i++)
      {
         if(sum+node[i].l >= wa) 
         {
             sum-=node[i].h;
             co_2++;
         }  
      }
      sort(node+1,node+n+1,cmp_3);
          for(i=1;i<=n;i++)
      {
         if(sum+node[i].l >= wa) 
         {
             sum-=node[i].h;
             co_3++;
         }  
      }
      co_1 = max(co_1 , co_2);
      co_1=max(co_1,co_3);
      printf("%d\n",co_1);
  }
  }
   return 0;
}