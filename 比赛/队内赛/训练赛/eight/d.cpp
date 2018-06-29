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
double dp[100005];
double son[100005];
vector<int>p[100005];
void dfs(int st)
{
  son[st] = 1;
  for(int i = 0;i<p[st].size();i++)
  {
    dfs(p[st][i]);
    son[st] += son[p[st][i]];
  }
}
void dfs_2(int st,int pre)
{
  double len = p[st].size();
  dp[st] = dp[pre] + 1.0 + (son[pre]-son[st]-1)/2;
  for(int i = 0;i<len;i++)
  {
    dfs_2(p[st][i],st);
  }
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  cin>>n;
  for(int i = 1;i<n;i++)
  {
    int a;
    cin>>a;
    p[a].push_back(i+1);
  }
  dfs(1);
  dp[1] = 1.0;
  for(int i = 0;i<p[1].size();i++)
  {
    dfs_2(p[1][i],1);
  }
  for(int i = 1;i<=n;i++)
  {
    cout<<dp[i]<<" ";
  }
  cout<<endl;
  return 0;
}
