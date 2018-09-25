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
vector<int>a[13];
vector<int>b[13];
vector<int>c[13];
vector<int>d[13];
void init()
{
  for(int i = 0;i<=10;i++)
  {
    a[i].clear();
    b[i].clear();
    c[i].clear();
    d[i].clear();
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t; cin>>t;
  int n,m;
  while(t--)
  {
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
      int num;cin>>num;
      for(int j = 1;j<=num;j++)
      {
        int op;cin>>op;
        a[i].pb(op);
      }
    }
    for(int i = 0;i<m;i++)
    {
      int num;cin>>num;
      for(int j = 1;j<=num;j++)
      {
        int op;cin>>op;
        c[i].pb(op);
      }
    }
    int vis[100];
    for(int i = 0;i<n;i++)
    {
      clr(vis,0);
      for(int j = 0;j<(1<<m);j++)
      {
        for(int k = 0;k<m;k++)
        {
          if(j&(1<<k))
          {
            for(int l = 0;l<c[k].size();l++)
            vis[c[k][l]] = 1;
          }
        }
        int flag = 1;
        for(int k = 0;k<a[i].size();k++)
        {
          if(!vis[a[i][j]]) flag = 0;
        }
        if(flag)
        b[i].pb(j);
      }
    }
    for(int i = 0;i<n;i++)
    {

    }

  }
  return 0;
}
