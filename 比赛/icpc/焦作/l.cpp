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
ll dp[10];
struct node
{
  ll p[9][9];
};
node mut(node a,node b)
{
  node o;
  clr(o.p,0);
  for(int i = 0;i<9;i++)
  {
    for(int j = 0;j<9;j++)
    {
      for(int k = 0;k<9;k++)
      {
        o.p[i][j] =( a.p[i][k] * b.p[k][j] + o.p[i][j])%mod;
      }
    }
  }
  return o;
}
node quick(node a,ll l)
{
  node origin;
  clr(origin.p,0);
  for(int i = 0;i<9;i++) origin.p[i][i] = 1;
  while(l)
  {
    if(l&1) origin = mut(a,origin);
    a = mut(a,a);
    l/=2;
  }
  return origin;
}
node init(node a)
{
  a.p[0][3] = a.p[0][6] = a.p[1][0] = a.p[1][6] = a.p[2][0] = a.p[2][3] = a.p[2][6] = 1;
  a.p[3][4] = a.p[3][1] = a.p[4][1] = a.p[4][7] = a.p[5][4] = a.p[5][7] = 1;
  a.p[6][2] = a.p[6][5] = a.p[6][8] = a.p[7][2] = a.p[7][8] = a.p[8][2] = a.p[8][5] = 1;
  return a;
}
int main()
{
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    ll n;
    cin >> n;
    if(n == 1) {cout<<3<<endl;continue;}
    if(n == 2) {cout<<9<<endl;continue;}
    for(int i = 0;i<9;i++)
    {
      dp[i] = 1;
    }
    node q;clr(q.p,0);
    q = init(q);
    q = quick(q,n-2);
    ll ans = 0;
    for(int i = 0;i<9;i++)
    {
      for(int j = 0;j<9;j++)
      {
        ans = (ans + q.p[i][j])%mod;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
