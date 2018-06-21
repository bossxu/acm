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
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
vector<int>map[505];
vector<int>q;
int n;int vis[505];

int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int m;
  while(cin>>n>>m)
  {
    for(int i = 1;i<=n;i++)
     map[i].clear();
     q.clear();
     clr(vis,0);
    for(int i = 1;i<=m;i++)
    {
      int a,b;
      cin>>a>>b;
      map[b].push_back(a);
    }
    for(int i = 1;i<=n;i++)
    {
      sort(map[i].begin(),map[i].end());
    }
    for(int i = 1;i<=n;i++)
    {
      int j;
      for(j = 1;j<=n;j++)
      {
        if(vis[j]) continue;
        int flag = 1;
        for(int k = 0;k<map[j].size() && flag;k++)
        {
          if(!vis[map[j][k]])
          {
            flag = 0;
          }
        }
        if(flag) break;
      }
      q.push_back(j);
      vis[j] = 1;
    }
    for(int i = 0;i<q.size()-1;i++)
    {
      cout<<q[i]<<" ";
    }
    cout<<q[q.size()-1];
    cout<<endl;
  }
  return 0;
}
