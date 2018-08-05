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
//#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
ll map[300005][2];
ll op[300005];
ll up_step[300005];
ll down_step[300005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    clr(op,0);
    clr(up_step,0);
    clr(down_step,0);
    for(int i = 1;i<=n;i++)
    {
      cin>>map[i][0];
    }
    for(int i = 1;i<=n;i++)
    {
      cin>>map[i][1];
    }
    for(int i = n;i>=1;i--)
    {
      op[i] = op[i+1] + map[i][1] + map[i][0];
    }
    for(int i = 1;i<=n;i++)
    {
      up_step[1] += map[i][0]*(i-1) + map[i][1]*(2*n-i);
      down_step[1] += map[i][1]*(i-1) + map[i][0]*(2*n-i);
    }
    for(int i = 2;i<=n;i++)
    {
      up_step[i] = up_step[i-1] - map[i-1][1]*((n-i+1)*2+1) - op[i];
      down_step[i] = down_step[i-1] - map[i-1][0]*((n-i+1)*2+1) - op[i];
    }
    ll maxn = up_step[1];
    ll ans = 0;
    int t = 0;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 0;j<2;j++)
      {
        int flag = j^((i+1)%2);
        ans += t*map[i][flag];
        t++;
        if(flag == 0 && i != 1)
        maxn = max(maxn,ans + up_step[i+1] + t*(op[i+1]));
        if(flag == 1)
        {
          if(i%2 == 1)
          {
            maxn = max(maxn,ans + down_step[i+1]+t*(op[i+1]));
          }
        }
      }
    }
    cout<<maxn<<endl;

  }
  return 0;
}
