#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 30005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

struct st{
    int yuan;
    int you;
}node[10005];
int cmp(st a, st b )
{
    if(a.yuan>b.yuan) return 1;
    return 0;
}
int main()
{
    int n,k;
    int l,p;
   while(scanf("%d",&n)==1)
   {
      for(int i=0;i<n;i++)
      {
          scanf("%d%d",&node[i].yuan,&node[i].you);
      }
      sort(node,node+n,cmp);
      scanf("%d%d",&l,&p);
      priority_queue<int>q;
      q.push(p);
      int ans=0,i=0;
      while(l>0 && !q.empty())
      {
          ans++;
          l-=q.top();
          q.pop();
          while( i<n && l<=node[i].yuan)
          q.push(node[i++].you);
      }
      printf("%d\n",l<=0?ans-1:-1);
   }
    return 0;
}