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
ll dp[205][205][2];
struct node
{
  int l,r;
  int val,op;
}Q[205];
int cmp(node a,node b)
{
  if(a.l == b.l) return a.r<b.r;
  return a.l<b.l;
}
int main()
{
  ios_close;
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  while(t--)
  {
    clr(dp,0);
    int n,m,K,w;
    cin>>n>>m>>K>>w;
    for(int i = 1;i<=m;i++)
    {
      cin>>Q[i].l>>Q[i].r>>Q[i].val>>Q[i].op;
    }
    sort(Q+1,Q+m+1,cmp);
    for(int i = 1;i<=m;i++)
    {
      for(int j = n;j>=0;j--)
      {
        for(int k = 0;k<=K;k++)
        {
          if(j<=Q[i].l)
          {

          }
          else
          {

          }
        }
      }
    }
  
  }
  return 0;
}
