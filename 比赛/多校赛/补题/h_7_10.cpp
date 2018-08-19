#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<" is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
int a,b,c,d,P,n;
// 自己的做法bug太多了
// 菜队的做法不错存那个矩阵，其实就是我们不去记录开始的东西
// 我们直接去记录
struct node
{
  ll p[3][3];
  node(){clr(p,0);}
};
node mut(node a,node b)
{
  node o;
  clr(o.p,0);
  for(int i = 0;i<3;i++)
  {
    for(int j = 0;j<3;j++)
    {
      for(int k = 0;k<3;k++)
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
  origin.p[1][1] = origin.p[0][0] = origin.p[2][2]= 1;
  while(l)
  {
    if(l&1) origin = mut(a,origin);
    a = mut(a,a);
    l/=2;
  }
  return origin;
}
node to;
void init()
{
  to.p[0][0] = d,to.p[0][1] = c;
  to.p[1][0] = to.p[2][2] = 1;
}
vector<ll>q;
vector<ll>op;
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  while(t--)
  {
    q.clear();
    op.clear();
    cin>>a>>b>>c>>d;
    cin>>P>>n;
    init();
    if(n == 1)  {cout<<a<<endl;continue;}
    if(n == 2)  {cout<<b<<endl;continue;}
    for(int i = 1;i*i<=P;i++)
    {
      q.pb(i);
      if(i*i!=P)
      q.pb(P/i);
    }
    sort(q.begin(),q.end(),greater<ll>());
    int len = q.size();
    for(int i = 0;i<len;i++)
    {
      op.pb(P/q[i]);
    }
    op.pb(mod);
    q.pb(0);
    int tot = 0;
    node ans;
    ans.p[0][0] = ans.p[1][1] = ans.p[2][2] = 1;
    for(int i = 3;i<=n;)
    {
      while(op[tot]<i ) tot++;
      node now = to;now.p[0][2] = q[tot];
    //  cout<<q[tot]<<endl;
      if(n <= op[tot])
      {
        // cout<<n-max(2*1LL,op[tot-1]);
        // debug;
        ans = mut(quick(now,n-max(2*1LL,op[tot-1])),ans);
        break;
      }
      else
      {
        // cout<<op[tot]-max(2*1LL,op[tot-1]);
        // debug;
        ans = mut(quick(now,op[tot]-max(2*1LL,op[tot-1])),ans);
        tot++;
      }
    }
    ll num = 0;
    num = (ans.p[0][0]*b+ans.p[0][1]*a+ans.p[0][2])%mod;
    cout<<num<<endl;
  }
  return 0;
}
