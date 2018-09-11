#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
int vis[(1<<25)+6];
string a;
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  while(true){
  cin>>n>>m;
  std::vector<ll> v;
  if(n <= 20)
  {
    for(int i = 1;i<=n;i++)
    {
      ll now = 0;
      cin >> a;
      for(int j = 0;j<m;j++)
      {
        now = now*2+a[j]-'0';
      }
      v.pb(now);
    }
    for(int i = 0;i<n;i++)
    {
      for(int j = 0;j<(1<<m);j++)
      {
        if(vis[j] == 0) continue;
        vis[j^v[i]] = max(vis[j^v[i]] , vis[j]+1);
      }
      vis[v[i]] = max(vis[v[i]],1);
    }
  }
  cout<<vis[0]<<endl;
}
  return 0;
}
