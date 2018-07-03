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
int ans[105];
int op[4];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  while(cin>>n>>k)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    int tot = 0;
    for(int i = 1;i<=n;i++)
    {
      op[shu[i]%2]++;
      if(op[1] == op[0] && i!=n)
      {
        ans[tot++] = abs(shu[i+1] - shu[i]);
      }
    }
    if(tot == 0)
    {
      cout<<0<<endl;
      continue;
    }
    else
    {
      sort(ans,ans+tot);
      int sum = 0;
      int num = 0;
      for(int i = 0;i<tot;i++)
      {
        sum+=ans[i];
        if(sum<=k)
        {
          num++;
        }
        else
        {
          break;
        }

      }
        cout<<num<<endl;
    }

  }
  return 0;
}
