#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
#define clr(a,x) memset(a,x,sizeof(a))
ll shu[100005];
int main()
{
  std::ios::sync_with_stdio(false);
  int n,k;
  ll l;
  while(cin>>n>>k>>l)
  {
    for(int i = 1;i<=n*k;i++)
    {
      cin>>shu[i];
    }
    sort(shu+1,shu+n*k+1);
    if(shu[n]-shu[1]>l)
    {
      cout<<0<<endl;
      continue;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
       ans+=shu[i];
    int le=2;
    int cnt=1;
    if(k==1)
     {
          cout<<ans<<endl;
          continue;
     }
           for(int i=n+1;i<=n*k;i++)
           {
               if(shu[i]-shu[1]<=l)
               {
                   if(cnt<k)
                   {
                       cnt++;
                       ans+=shu[i];
                       ans-=shu[le];
                       le++;
                       if(cnt==k)
                       {
                           cnt=1;
                           le++;
                       }
                   }
               }
           }
           cout<<ans<<endl;
  }
  return 0;
}
