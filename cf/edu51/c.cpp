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
int shu[105];
int csl[105];
int atm[105];
vector<int>q[3];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    q[1].clear();
    q[2].clear();
    clr(shu,0);
    for(int i = 1;i<=n;i++)
    {
      cin>>csl[i];
      shu[csl[i]]++;
    }
    for(int i = 1;i<=100;i++)
    {
      atm[i] = 1;
      if(shu[i] == 1) q[1].pb(i);
      if(shu[i] >= 3) q[2].pb(i);
    }
    if(q[1].size()%2 == 1 && q[2].size() == 0)
    {
      cout<<"NO"<<endl;
      continue;
    }
    cout<<"YES"<<endl;
    if(q[1].size()%2 == 0)
    {
      for(int i = 0;i<q[1].size();i+=2)
      {
        atm[q[1][i]] = 0;
      }
      for(int i = 1;i<=n;i++)
      {
        if(atm[csl[i]]) cout<<'A';
        else cout<<'B';
      }
      cout<<endl;
    }
    else
    {
      for(int i = 1;i<q[1].size();i+=2)
      {
        atm[q[1][i]] = 0;
      }
      int vis[105];
      for(int i = 1;i<=n;i++)
      {
        if(atm[csl[i]]) vis[i] = 1;
        else vis[i] = 0;
      }
      for(int i = 1;i<=n;i++)
      {
        if(csl[i] == q[2][0])
        {
          vis[i] = 0;
          break;
        }
      }
    //  debug;
      for(int i = 1;i<=n;i++)
      {
        if(vis[i]) cout<<'A';
        else cout<<'B';
      }
      cout<<endl;
    }

  }

  return 0;
}
