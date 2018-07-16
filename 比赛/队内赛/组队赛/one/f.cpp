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
int shu[100005];
int ans[1000005];
void init()
{
  clr(ans,0);
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
      int n;
      cin>>n;
      int maxn = 0;
      for(int i = 1;i<=n;i++)
      {
        cin>>shu[i];
        maxn = max(shu[i],maxn);
      }
      sort(shu+1,shu+n+1);
      clr(ans,0);
      for(int i = 1;i<=n;i++)
      {
        if(ans[shu[i]]) continue;
        for(int k = shu[i]; k<=maxn;k+=shu[i])
        {
          if(ans[k]) continue;
          ans[k] = shu[i];
        }
      }
      ll sum = 0;
      for(int i = 1;i<=n;i++)
      {
        sum+=ans[shu[i]];
      }
      cout<<sum<<endl;
   }
  return 0;
}
