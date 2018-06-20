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
struct Node
{
  ll zhi;
  int ind;
}shu[200005];
ll ans[200005];
int cmp(Node a, Node b)
{
  return a.zhi<=b.zhi;
}
int n;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  int t;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d",&n);
      for(int i = 1;i<=n;i++)
      {
        scanf("%lld",&shu[i].zhi);
      }
   for(int i = 1;i<=n;i++)
      {
        shu[i].ind = i;
      }
      clr(ans,0);
      sort(shu+1,shu+n+1,cmp);
      int index = -1;
      for(int i = 2;i<=n;i++)
      {
        if(shu[i].zhi+shu[1].zhi > mod)
        {
          index = i;
          break;
        }
      }
      if(index == -1)
      {
        index = n;
      }
      else
      index--;
      for(int i = 1;i<=n;i++)
      {
        while(index>0 && (shu[i].zhi+shu[index].zhi>=mod))
        { index--;}
        if(index == i) index--;
        //cout<<shu[i].ind<<endl;
        if(index>0)
        {
          ans[shu[i].ind] = shu[i].zhi+shu[index].zhi;
        }
        if(i!=n)
        ans[shu[i].ind] = max(ans[shu[i].ind],(shu[i].zhi+shu[n].zhi)%mod);
        else
        ans[shu[i].ind] = max(ans[shu[i].ind],(shu[i].zhi+shu[n-1].zhi)%mod);
      }

      for(int i = 1;i<n;i++)
      {
        printf("%lld ",ans[i]);
      }
      printf("%lld\n",ans[n]);
  }
  return 0;
}
