#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 30003
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int N,M;
int par[maxn],ra[maxn];
void init()     //父亲节点初始化
{
  for(int i=0;i<maxn;i++)
  {
      par[i]=i;
      ra[i]=1;
  }
  return ;
}
int Find(int x)  // 找根节点
{  
    if(x!=par[x])  
    {  
        par[x]=Find(par[x]);  
    }  
    return par[x];  
}  
void bing(int x, int y)
{
    int a = Find(x);
    int b = Find(y);
    if (a==b) return;
    if(ra[a]>=ra[b])  
    {  
        par[b]=a;  
        ra[a]=ra[a]+ra[b];  
    }else  
    {  
        par[a]=b;  
        ra[b]=ra[b]+ra[a];  
    }  

}
int main()
{
    int t;
   while(cin>>N>>M)
   {
       if(N==0 && M==0) break;
      init(); 
      while(M--)
      {
        int t,first,k;
        scanf("%d %d",&t,&first);
        for( int i=1;i<t;i++)
        {
          scanf("%d",&k);
          bing(first,k);
        }
        //printf("%d %d\n",ra[par[0]],par[2]);
      }
      printf("%d\n",ra[Find(0)]);
   }
    return 0;
}