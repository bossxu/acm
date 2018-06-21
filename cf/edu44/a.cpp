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
int shu[105];
int vis[105];
int main()
{
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    clr(shu,0);
    int a;
    int minn = INF;
    int ans = 0;
    for(int i = 1;i<=n/2;i++)
    {
      cin>>shu[i];
    }
    sort(shu+1,shu+n/2+1);
    for(int i = 1;i<=n/2;i++)
    {
      ans +=abs(shu[i]-i*2+1);
    }
    minn = ans;
    ans =0 ;
    for(int i = 1;i<=n/2;i++ )
    {
      ans+=abs(shu[i]-2*i);
    }
    minn = min(ans,minn);
    cout<<minn<<endl;

  }

  return 0;
}
