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
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
int shu[10];
int main()
{
  std::ios::sync_with_stdio(false);
  //cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    clr(shu,0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
      int a;
      cin>>a;
      shu[a]++;
    }
    int ans = 0;
    ans+=shu[4]+shu[3];
    shu[1]-=shu[3];
    ans+=shu[2]/2;
    shu[2]%=2;
    if(shu[2])
    {
      ans+=1;
      shu[1]-=2;
    }
    if(shu[1]>0)
    {
      ans+=shu[1]/4;
    }
    if(shu[1]>0 && shu[1]%4)
    {
      ans+=1;
    }
    cout<<ans<<endl;
  }
  return 0;
}
