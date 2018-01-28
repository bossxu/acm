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
void init()
{
    for(i=1;i<=20002;i++)
    {
     par[i]=i;
     ra[i]=1;
    }
    ra[0]=0;
}
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
      scanf("")
      init();
  }

}