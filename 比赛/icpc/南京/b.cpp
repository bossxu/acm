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
int shu[100005][105];
int n,m,k;
void init()
{
  //row
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      if(shu[i][j] == 1)
      {
        shu[i][j] = 0;
      }
      else
      {
        shu[i][j] = shu[i][j-1]+1;
      }
    }
  }
  //every
  for(int i = 1;i<=n;i++)
  {
    
  }
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    clr(shu,0);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=k;i++)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      shu[a][b] = 1;
    }
  }
  return 0;
}
