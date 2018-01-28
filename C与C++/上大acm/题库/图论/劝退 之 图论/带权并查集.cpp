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
int ra[50005],pre[50005];
int N;
// { 0 表示 同类 。。1 表示 他被父亲结点吃。。。。2表示 父亲节点吃他 }
int find(int x)
{
  if(pre[x]==x)return x;
    int tmp=find(pre[x]);
    ra[x]+=ra[pre[x]];
    ra[x]%=3;
    return pre[x]=tmp;
}
void init()
{
    int i;
    for(i=1;i<=N;i++)
    {
      pre[i]=i;
      ra[i]=0;
    }
}
bool bing(int a, int b,int c)
{
   int x=find(a);
   int y=find(b);
   if(x!=y)
   {
      if(c==1)//这里的目的，在于对y来说，节点更新了，所以它的权值也要更新
      {
          pre[y]=x;
          ra[y]=ra[a]-ra[b];
          ra[y]=(ra[y]+3)%3;
      }
      if(c==2)//同理
      {
          pre[y]=x;
          ra[y]=ra[a]-ra[b]+1;
          ra[y]=(ra[y]+3)%3;
      }
      return true;
   }
   if(x==y)
   {
      if(c==1 && ra[a]==ra[b])
      {return true;}
      if(c==2 && (ra[a]+1)%3==ra[b])
      {return true;}
   }
     return false;
}
int main()
{
    int t;
      scanf("%d%d",&N,&t);
      init();
      int sum=0;
      int a,b,c;
      while(t--)
      {
          scanf("%d%d%d",&a,&b,&c);
          if(b>N || c>N)
          {sum++;continue;}
          if (! bing(b,c,a)) sum++;
      }
      printf("%d\n",sum);
      //system("pause");
    return 0;
}
