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
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int shu[7];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    int a;
    clr(shu,0);
    for(int i = 1;i<=n;i++)
    {
      cin>>a;
      shu[a]++;
    }
    int ans = 0;
    ans+=shu[5];
    ans+=shu[4];
    shu[1]-=shu[4];
    ans+=shu[3];
    if(shu[2]>=shu[3])
      {
        shu[2]-=shu[3];
      }
    else
      {
        shu[1]-=2*(shu[3]-shu[2]);
        shu[2] = 0;
      }
    if(shu[2]>0)
    {
    ans+=shu[2]/2;
    shu[1]-=shu[2]/2;
    shu[2] = shu[2]%2 == 0?0:1;
    }
    if(shu[2]>0)
    {
      ans++;
      shu[1]-=3;
    }
    if(shu[1]>0)
    {
      int l = shu[1]/5;
      if(shu[1]%5 != 0) l++;
      ans+=l;
    }
    cout<<ans<<endl;
  }
  return 0;
}
