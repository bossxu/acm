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

ll C[1005][1005];
ll n,m;
void init()
{
  clr(C,0);
  C[0][0]=1;
  for(int i = 1;i<=1000;i++)
  {
    C[i][i] = 1;
    C[i][0] = 1;
    for(int j = 1;j<i;j++)
    {
      C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
    }
  }
}
ll sum = 0;
int a[20];
void dfs(int st)
{
  //cout<<"hello"<<endl;
  //cout<<q.size()<<endl;
  if(st == m)
  {
    ll ans = 1;
    for(int i = m-1;i>=1;i--)
    {
      ans = ans*C[a[i]][a[i-1]]%mod;
    }
    sum += ans;
    return;
  }
  else
  {
    for(int i = a[st-1];i<=n;i++)
    {
      a[st] = i;
      dfs(st+1);
    }
  }
}
int main()
{
  ios_close;
  int t;
  init();
  freopen("out.txt","w",stdout);
  for(int i = 1;i<=10;i++)
  {
    for(int j = 1;j<=10;j++)
    {
      n = i,m = j;
      sum = 0;
      for(int i = 0;i<=n;i++)
      {
          a[0] = i;
          dfs(1);
      }
      cout<<"sum["<<i<<","<<j<<"]="<<sum<<"  ";
    }
    cout<<endl;
  }

  return 0;
}
