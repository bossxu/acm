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
    int rank;
    int bian;

};
int cmp(st a , st b)
{
    if(a.rank<b.rank) return 1;
    return 0;
}
int main()
{
   int n,k;
   scanf("%d%d",&n,&k);
      st node[maxn];
      for(int i=1;i<=n;i++)
      {
          scanf("%d",&node[i].rank);
          node[i].bian=i;
      }
      sort(node+1,node+n+1,cmp);
      for(int i=1;i<=k;i++)
      {
          int a;
          scanf("%d",&a);
          int c=0,x=0;
          while(c!=i)
          {
             if(node[++x].bian<=a) 
              c++;
          }
          printf("%d\n",node[x].rank);
      }
     //system("pause");
    return 0;
}