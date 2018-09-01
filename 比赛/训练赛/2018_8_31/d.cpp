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

vector<int>shu[5];
int main()
{
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    for(int i = 0;i<4;i++) shu[i].clear();
    int n;
    cin>>n;
    int a;
    for(int i = 1;i<=n;i++) //man
    {
      cin>> a;
      if(a>0) shu[0].pb(a);
      else shu[1].pb(-a);
    }
    for(int i = 1;i<=n;i++) //woman
    {
      cin>> a;
      if(a>0) shu[2].pb(a);
      else shu[3].pb(-a);
    }
    for(int i = 0;i<4;i++)
    {
      if(!shu[i].empty())
      sort(shu[i].begin(),shu[i].end(),greater<int>());
    }
    int len = shu[2].size();
    int tot=0;
    int ans = 0;
    for(int i = 0;i<shu[1].size();i++)
    {
      while(tot<len && shu[1][i]<=shu[2][tot])
      {
        tot++;
      }
      if(tot >= len) break;
      if(shu[1][i]>shu[2][tot]) ans++,tot++;
    }
    tot = 0;
    len = shu[0].size();
    for(int i = 0;i<shu[3].size();i++)
    {
      while(tot<len && shu[3][i]<=shu[0][tot])
      {
        tot++;
      }
      if(tot >= len) break;
      if(shu[3][i]>shu[0][tot]) {ans++;tot++;}
    }
    cout<<ans<<endl;
  }
  return 0;
}
