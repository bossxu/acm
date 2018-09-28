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
char s[20][20];
char a[20];
vector<char> v[20];
int n;
vector<char> op;
bool small_check(int tot,int st,int len)
{
  int now = 0;int en = op.size();
  for(int i = 0;i<len;i++)
  {
    if(op[now] == v[tot][st+i])
    now++;
    if(now == en) break;
  }
  return (now == en);
}
bool check()
{
  bool flag = 1;
  for(int i = 2;i<=n;i++)
  {
    int op = 0;
    int len = v[i].size()/2;
    for(int j = 0;j<len;j++)
    {
      if(small_check(i,j,len))
      op = 1;
    }
    if(!op)
    flag = 0;
  }
  return flag;
}
int main()
{
  ios_close;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      v[i].clear();
      cin>>s[i];
    }
    int len = strlen(s[1]);
    for(int i = 1;i<=n;i++)
    {
      int m = strlen(s[i]);
      for(int j = 0;j<m;j++)
        v[i].pb(s[i][j]);
      for(int j = 0;j<m;j++)
        v[i].pb(s[i][j]);
    }
    int tot = 0;
    vector<char>ans;
    for(int i = 0;i<len;i++)
    {
      for(int j = 1;j<(1<<len);j++)
      {
        op.clear();tot = 0;
        for(int k = 0;k<len;k++)
        {
          if(j & (1<<k))
          op.pb(v[1][i+k]),tot++;
        }
        if(check())
        {
          // for(int l = 0;l<op.size();l++)
          // {
          //   cout<<op[l];
          // }
          // cout<<endl;
          if(tot == ans.size())
          {
            int chan = 0;
            for(int i = 0;i<ans.size();i++)
            {
              if(ans[i] == op[i]) continue;
              if(ans[i] < op[i]) break;
              if(ans[i]>op[i])
              {chan = 1;break;}
            }
            if(chan == 1)
            {
              ans.clear();
              for(int l = 0;l<tot;l++)
              ans.pb(op[l]);
            }
          }
          if(tot>ans.size())
          {
            ans.clear();
            for(int l = 0;l<tot;l++)
            ans.pb(op[l]);
          }
        }
      }
    }
    if(ans.size() == 0) cout<<0<<endl;
    else
    {
      for(int i = 0;i<ans.size();i++)
      {
        cout<<ans[i];
      }
      cout<<endl;
    }
  }
  return 0;
}
