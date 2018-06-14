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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  scanf("%d",&t);
  int shu[20];
  int n,k;
  while(t--)
  {
    cin>>n>>k;
    for(int i = 1;i<=n;i++)
    {
      scanf("%d",&shu[i]);
    }
    sort(shu+1,shu+n+1);
    if(k == 1)
    {
      int ans = -1;
      for(int i = n;i>=1;i--)
      {
        if(shu[i]%3 == 0)
        {
          ans = shu[i];
          break;
        }
      }
      printf("%d\n",ans);
    }
    if(k == 2)
    {
      int ans = -1;
      for(int i = n;i>=1;i--)
      {
        for(int j = n;j>=1;j--)
        {
          if((shu[i]+shu[j])%3 == 0)
          {
            ans = max(ans,shu[i]*10+shu[j]);
          }
        }
      }
      if(ans == 0) printf("-1\n");
      else
      printf("%d\n",ans);
    }
    if(k >= 3)
    {
      int ans = -1;
      int l = (k-3)*shu[n]%3;
      //cout<<l<<endl;
      for(int i = n;i>=1;i--)
      {
        for(int j = n;j>=1;j--)
        {
          for(int p = n;p>=1;p--)
          if((shu[i]+shu[j]+shu[p]+l)%3 == 0)
          {
            ans = max(ans,shu[i]*100+shu[j]*10+shu[p]);
          }
        }
      }
      if(ans == -1 || ans == 0)
      {
        cout<<"-1"<<endl;
        continue;
      }
      for(int i = 1;i<=k-3;i++)
      {
        printf("%d",shu[n]);
      }
      cout<<ans<<endl;
    }
  }

  return 0;
}
