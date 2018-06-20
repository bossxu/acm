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
int shu[1000005];
int ans[1000005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    clr(ans,0);
    for(int i = 1;i<=n;i++)
    {
      scanf("%d",&shu[i]);
    }
    int maxn = shu[1];
    for(int i =2;i<n;i++)
    {
      if(shu[i]>=maxn)
      {
        ans[i] = -1;
        maxn = shu[i];
      }
    }
    int minn = shu[n];
    for(int i = n-1;i>=2;i--)
    {
      if(shu[i]<=minn)
      {
        ans[i]+=2;
        minn = shu[i];
      }

    }
    int num = 0;
    for(int i = 1;i<=n;i++)
    {
      if(ans[i] == 1)
      {
        num++;
      }
    }
    printf("%d\n",num);
  }
  return 0;
}
