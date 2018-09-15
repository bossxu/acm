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
    ll x,y;
}Q[5005];
int vis[5005];
ll dp[5005];
int cmp(node a,node b)
{
  if(a.x == b.x) return a.y>b.y;
  else return a.x<b.x;
}
int main()
{
  ios_close;
  int n;
  while(cin>>n)
  {
    clr(vis,0);
    clr(dp,INF);
    for(int i = 1;i<=n;i++)
    {
      cin>>Q[i].x>>Q[i].y;
      Q[i].x = abs(Q[i].x);
      Q[i].y = abs(Q[i].y);
    }
    sort(Q+1,Q+n+1,cmp);
    ll my=Q[n].y;
    for(int i=n-1;i>=1;i--)
    {
      if(Q[i].y<=my)
        vis[i]=1;
      my=max(my,Q[i].y);
    }
    int tot = 0;
    for(int i = 1;i<=n;i++)
    {
      if(vis[i]) continue;
      Q[++tot] = Q[i];
    }
    dp[0] = 0;
    for(int i = 1;i<=tot;i++)
    {
      for(int j = 0;j<i;j++)
      {
        dp[i] = min(dp[j]+Q[i].x*Q[j+1].y,dp[i]);
      }
    //  cout<<dp[i]<<" "<<i<<endl;
    }
    cout<<dp[tot]*4<<endl;

  }
  return 0;
}
