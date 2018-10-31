//langman
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-7;
vector<ll>q;
vector<double>ans;
struct node
{
  double p[2][2];
};
node mut(node a,node b)
{
  node o;
  clr(o.p,0);
  for(int i = 0;i<2;i++)
  {
    for(int j = 0;j<2;j++)
    {
      for(int k = 0;k<2;k++)
      {
        o.p[i][j] =a.p[i][k] * b.p[k][j] + o.p[i][j];
      }
    }
  }
  return o;
}
node quick(node a,ll l)
{
  node origin;
  clr(origin.p,0);
  origin.p[1][1] = origin.p[0][0] = 1.0;
  while(l)
  {
    if(l&1) origin = mut(a,origin);
    a = mut(a,a);
    l/=2;
  }
  return origin;
}

int main()
{
  int n;
  while(scanf("%d",&n) == 1)
  {
<<<<<<< HEAD
    clr(dp,0);
    clr(op,0);
    clr(vis,0);
    int a,b;
    int x,y;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        scanf("%c",&shu[i][j]);
        if(shu[i][j] == '$') b = cal(i,j);
        if(shu[i][j] == '@') a = cal(i,j),x = i,y = j;
      }
=======
    q.clear();
    double P;
    scanf("%lf",&P);
    for(int i = 1;i<=n;i++)
    {
      ll op;scanf("%lld",&op);
      q.pb(op);
>>>>>>> 7c1af85bb6e8bd4ac4461a18ad5bfaa1fa25030c
    }
    sort(q.begin(),q.end());
    double base = 1.0;
    double pre = 1.0;
    if(q[0] == '1')
    {
      printf("0.0000000\n");
      continue;
    }
    ll pr = 1;
    double ans = 1;
    for(int i = 0;i<n;i++)
    {
<<<<<<< HEAD
      for(int j = 1;j<=m;j++)
      {
        int tot = num(i,j);
        if(shu[i][j] == '$') continue;
        if(tot == 0)
        {  dp[cal(i,j)] = INF;  continue; }
        op[cal(i,j)][cal(i,j)] = 1;
        if(check(i+1,j)) op[cal(i,j)][cal(i+1,j)] = -1.0/tot;
        if(check(i,j+1)) op[cal(i,j)][cal(i,j+1)] = -1.0/tot;
        if(check(i-1,j)) op[cal(i,j)][cal(i-1,j)] = -1.0/tot;
        if(check(i,j-1)) op[cal(i,j)][cal(i,j-1)] = -1.0/tot;
      }
=======
      node a;
      clr(a.p,0);
      a.p[0][0] = P;
      a.p[0][1] = 1-P;
      a.p[1][0] = 1.0;
      a = quick(a,q[i]-pr);
      base = a.p[0][0]*pre;
      ans -= base;
      base = a.p[1][0]*pre;
      base = base *(1-P);
      //cout<< base << endl;
      pre = base;
      pr = q[i]+1;
>>>>>>> 7c1af85bb6e8bd4ac4461a18ad5bfaa1fa25030c
    }
    if(ans > eps)
    printf("%.7f\n",ans);
    else
    printf("0.0000000\n");
  }
  return 0;
}
