#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
vector<int>son[100005];
int dfs(int now,int pre)
{
  int maxn = 0;
  for(int i = 0;i<son[now].size();i++)
  {
    int to = son[now][i];
    if(to == pre) continue;
    maxn = max(maxn,dfs(son[now][i],now));
  }
  return maxn+1;
}
int main()
{
  ios_close;
  int n,st;
  while(cin>>n>>st)
  {
    int u,v;
    for(int i = 1;i<=n;i++) son[i].clear();
    for(int i =1;i<n;i++)
    {
      cin>>u>>v;
      son[u].pb(v);
      son[v].pb(u);
    }
    cout<<dfs(st,-1)<<endl;
  }
  return 0;
}
