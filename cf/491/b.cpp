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
double shu[105];
double k = 4.500;
int main()
{
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    double sum = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      sum+=shu[i];
    }
    sort(shu+1,shu+n+1);
    int ans = 0;
    if(sum/(double)n >= k)
    {
      cout<<0<<endl;
      continue;
    }
    for(int i = 1;i<=n;i++)
    {
      sum+=5.0-shu[i];
      ans++;
      if(sum/(double)n >= k)
      {
        break;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
