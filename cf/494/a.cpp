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
int shu[105];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
    int ans = 0;
    clr(shu,0);
    for(int i = 1;i<=n;i++)
    {
      int a;
      cin>>a;
      shu[a]++;
    }
    for(int i = 1;i<=100;i++)
    {
      ans = max(ans,shu[i]);
    }
    cout<<ans<<endl;
  }

  return 0;
}
