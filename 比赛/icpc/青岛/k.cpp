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
int shu[40];
int main()
{
  int t;scanf("%d",&t);
  while(t--)
  {
    int n;scanf("%d",&n);
    clr(shu,0);
    for(int i = 1;i<=n;i++)
    {
      ll op;scanf("%lld",&op);
      for(int j = 35;j>=0;j--)
      {
        if(op & (1LL<<j))
        {
          shu[j]++;
          break;
        }
      }
    }
    int maxn = 0;
    for(int i = 0;i<35;i++)
    {
      maxn = max(shu[i],maxn);
    }
    printf("%d\n",maxn);
  }
  return 0;
}
