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
int shu[100005];
int remain[100005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    if(n == 1)
    {
      cout<<0<<endl;
      continue;
    }
    sort(shu+1,shu+n+1);
    int tot = 1;
    for(int i = 2;i<=n;i++)
    {
      if(shu[i]!=shu[i-1])
      {
        tot = i;
        break;
      }
    }
    int ans = 0;
    //cout<<tot<<endl;
    for(int i = 1;i<=n&&tot<=n;i++)
    {
      if(shu[tot]>shu[i])
      {
        tot++;
        ans++;
      }
      else
      {
        while(tot<=n && shu[i]==shu[tot]) tot++;
        if(tot>n) break;
        ans++;
        tot++;
      }
    }
    cout<<ans<<endl;

  }
  return 0;
}
