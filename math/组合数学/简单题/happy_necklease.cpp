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

struct node
{
  ll p[3][3];
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
  origin.p[2][2] = origin.p[1][1] = origin.p[0][0] = 1;
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
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    node q;
    clr(q.p,0);
    q.p[0][0] = q.p[0][2] = q.p[1][0] = q.p[2][1] = 1;
    q = quick(q,n-2);
    ll num = 0;
    for(int i = 0;i<3;i++)
    {  for(int j = 0;j<3;j++)
      {
      //  cout<<q.p[i][j]<<" ";
        num += q.p[i][j];
      }
      //cout<<endl;
    }
    num%=mod;
    cout<<num<<endl;
  }
  return 0;
}
