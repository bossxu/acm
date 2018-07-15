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
const int N = 1<<20 + 5;
#define clr(a,x) memset(a,x,sizeof(a))
//题目的解法是多源bfs
//第一次碰到这种做法
//有点东西
int vis[N];
char s[30];
int n,m;
queue<int>q;
void init()
{
  int ok = 0;
  for(int i = 0;i<m;i++)
  {
    ok = ok*2+s[i]-'0';
  }
  vis[ok] = 1;
  q.push(ok);
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  //int n,m;
  while(cin>>n>>m)
  {
    clr(vis,0);
    //q.clear();
    for(int i = 1;i<=n;i++)
    {
      cin>>s;
      init();
    }
    while(!q.empty())
    {
      int ok = q.front();
      q.pop();
      for(int i = 0;i<m;i++)
      {
        if((1<<i)&ok)
        {
          int op = ok-(1<<i);
          if(vis[op]) continue;
          vis[op] = vis[ok]+1;
          q.push(op);
        }
        else
        {
          int op = ok+(1<<i);
          if(vis[op]) continue;
          vis[op] = vis[ok]+1;
          q.push(op);
        }
      }
    }
    int ans = 0;
    for(int i = 0;i<(1<<m);i++)
    {
      if(vis[i]>vis[ans])
      {
        ans = i;
      }
    }
    int shu[22];
    for(int i = 1;i<=m;i++)
    {
      shu[i] = ans%2;
      ans/=2;
    }
    for(int i = m;i>=1;i--)
    {
      cout<<shu[i];
    }
    cout<<endl;
  }
  return 0;
}
