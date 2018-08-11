#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;

int vis[800005];
vector<int>q[500005];
int main()
{
  int n;
  while(scanf("%d",&n) == 1)
  {
    clr(vis,0);
    ll op = 0;
    for(int i = 1;i<=n;i++)
    {
      q[i].clear();
      int a;
      scanf("%d",&a);
      op^=a;
      if(!vis[a])
      q[1].pb(a);
      vis[a] = 1;
    }
    if(op == 0)
    {
      printf("%d\n",n);
      continue;
    }
    int con = 1;
    while(con<n)
    {
      con++;
      if(vis[op]) break;
      int xia = con/2;
      int shang = con - xia;
      int len1 = q[xia].size();
      int len2 = q[shang].size();
      for(int i = 0;i<len1;i++)
      {
        for(int j = 0;j<len2;j++)
        {
          int k = q[xia][i]^q[shang][j];
          if(!vis[k])
          {
            vis[k] = xia + shang;
            q[con].pb(k);
          }
        }
      }

    }
    if(vis[op] == 0) printf("0\n");
    else printf("%d\n",n-vis[op]);
  }

  return 0;
}
