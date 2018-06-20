#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int shu[2000];
int n,m;
int ok(int a)
{
  int k = a%n;
  return k == 0?n:k;
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
   //std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  while (t--)
  {
      scanf("%d%d",&n,&m);
      for(int i = 1;i<=n;i++)
      {
        scanf("%d",&shu[i]);
      }
      int item = -1;
      for(int i = 1;i<=n;i++)
      {
        if(shu[i]!=-1)
        {
          item = i;
          break;
        }
      }
      for(int i = item+1;i<=n;i++)
      {
        shu[i] = (shu[i-1]+1)%m;
      }
      for(int i = item-1;i>0;i++)
      {
        shu[i] = (shu[i+1]-1+m)%m;
      }
      for(int i = 1;i<n;i++)  printf("%d ",shu[i]);
      printf("%d\n",shu[n]);
  }

  return 0;
}
