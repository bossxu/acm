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
// 坑点 在于一个是q没排序 一个是输入 ".lf" 输出应该是 ".f" 一个是输出 -0.0000000 
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
    q.clear();
    double P;
    scanf("%lf",&P);
    for(int i = 1;i<=n;i++)
    {
      ll op;scanf("%lld",&op);
      q.pb(op);
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
    }
    if(ans > eps)
    printf("%.7f\n",ans);
    else
    printf("0.0000000\n");
  }
  return 0;
}
