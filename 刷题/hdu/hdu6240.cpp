//langman
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
// 01分数规划的思想
// dp，重构价值来check()；
const int N = 1e5+5;
struct node
{
  int l,r;
  double a,b;
  double val;
}Q[N];
double dp[N];
int n,r;
bool check(double st)
{
  for(int i = 1;i<=n;i++)
  {
    Q[i].val = Q[i].a-Q[i].b*st;
  }
}
int cmp(node k,node p)
{
  if(k.l == p.l)
  {
    return k.r<p.r;
  }
  else
  return k.l<p.l;
}
int main()
{
  ios_close;
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>r;
    double li = 0,ri = 1000;
    for(int i = 1;i<=n;i++)
    {
      cin>>Q[i].l>>Q[i].r>>Q[i].a>>Q[i].b;
      Q[i].val = 0;
    }
    sort(Q+1,Q+n+1,cmp);
    while(li<ri)
    {
      double mid = (li+ri)/2;
      if(check(mid))
      {

      }
    }
  }
  return 0;
}
