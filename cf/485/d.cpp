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
vector<int>map[100005];
int a[100005];
int vis[100005];
int dp[100005][105];
int n,m,k;
struct node
{
  int ab;
  int step;
  node(){};
  node(int a,int b)
  {
    ab = a,step = b;
  }
};
int s;
int bfs(int st)
{
    queue<node>q;
    for(int i = 1;i<=n;i++)
    {
      if(a[i] == st)
      {
        q.push(node(i,0));
        vis[i] = 1;
      }
    }
  //cout<<"he;llo"<<endl;
  while(!q.empty())
{
  node l = q.front();
  q.pop();
  int now = l.ab;
  for(int i = 0;i<map[now].size();i++)
  {
    int to = map[now][i];
    if(!vis[to])
    {
      dp[to][st] = l.step+1;
      vis[to] = 1;
      q.push(node(to,l.step+1));
    }
  }
 }
}
int cmp(int b,int c)
{
  return b<c;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   while(cin>>n>>m>>k>>s)
   {
     clr(dp,INF);
     for(int i = 1;i<=n;i++)
     {
       cin>>a[i];
       dp[i][a[i]] = 0;
     }
     for(int i = 1;i<=m;i++)
     {
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
     }
     for(int i = 1;i<=k;i++)
     {
       clr(vis,0);
       bfs(i);
     }
     for(int i = 1;i<=n;i++)
     {
       sort(dp[i]+1,dp[i]+1+k,cmp);
     }
     for(int i = 1;i<=n;i++)
     {
       int ans = 0;
       for(int j =1;j<=s;j++)
       {
         ans+=dp[i][j];
       }
       cout<<ans<<" ";
     }
     cout<<endl;
   }
  return 0;
}
