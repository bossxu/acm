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
    int minn = 1;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      if(shu[i]<shu[minn])
      {
        minn = i;
      }
    }
    ll sum = 0;
    sort(shu+1,shu+n+1);
    if(n == 1)
    {
      cout<<-1<<endl;
      continue;
    }
    for(int i = 2;i<=n;i++)
    {
      sum+=shu[i];
    }
    if(shu[1] == sum)
    {
      cout<<-1<<endl;
    }
    else
    {
      cout<<1<<endl;
      cout<<minn<<endl;
    }
  }
  return 0;
}
