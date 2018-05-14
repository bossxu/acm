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
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
int shu[100];
bool vis[1005];
int ans[100];
int main()
{
  int n;
  while(cin>>n)
  {
    clr(vis,0);
    int flag = 1;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    for(int i = n;i>=1;i--)
    {
      if(!vis[shu[i]])
      {
        ans[flag++] = shu[i];
        vis[shu[i]] = 1;
      }
    }
    cout<<flag-1<<endl;
    for(int i = flag-1;i>1;i--)
    {
      cout<<ans[i]<<" ";
    }
    cout<<ans[1]<<endl;
  }
  return 0;
}
