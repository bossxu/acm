#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
ll shu[400001];
vector<int>son[400001];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    for(int i = 1;i<n;i++)
    {
      int u,v;
      cin>>u>>v;
      son[u].pb(v);
      son[v].pb(u);
    }
    
  }
  return 0;
}
