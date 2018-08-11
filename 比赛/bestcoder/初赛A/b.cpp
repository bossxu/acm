#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define pf push_front
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
list<int>shu[1<<20];

int main()
{
  int n,m;
  while(scanf("%d%d",&n,&m) == 2)
  {
    for(int i = 1;i<=n;i++)
    {
      shu[i].clear();
    }
    int op,u,v,w,val;
    while(m--)
    {
      scanf("%d",&op);
      if(op == 1)
      {
        scanf("%d%d%d",&u,&w,&val);
        if(w == 0)
          shu[u].pf(val);
        else
          shu[u].pb(val);
      }
      if(op == 2)
      {
        scanf("%d%d",&u,&w);
        if(!shu[u].empty())
        {
          if(w == 0)
          {
            printf("%d\n",shu[u].front());
            shu[u].pop_front();
          }
          else
          {
            printf("%d\n",shu[u].back());
            shu[u].pop_back();
          }
        }
        else
        printf("-1\n");
      }
      if(op == 3)
      {
        scanf("%d%d%d",&u,&v,&w);
        {
          if(!shu[v].empty())
          {
            if(!w)
            {
              shu[u].splice(shu[u].end(),shu[v]);
            }
            else
            {
              shu[v].reverse();
              shu[u].splice(shu[u].end(),shu[v]);
            }
            shu[v].clear();
          }
        }
      }
    }
  }
  return 0;
}
