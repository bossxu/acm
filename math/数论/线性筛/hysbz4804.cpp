#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 10000006;
// 纯粹的推公式的题
// 但是其实很难想到，预处理，并且要猜出来那个后面的式子为积性函数
//点在于 1：推出公式 2：猜出这个是可以预处理的 3：知道线性筛怎么筛 4：会分块
int prim[N/10+5],num;
int vis[N+5];
ll dp[N+5];
void pre()
{
  dp[1] = 1;num = 0;
  for(int i = 2;i<=N;i++)
  {
    if(!vis[i])
    {
      prim[++num] = i;
      dp[i] = i-2;
    }
    for(int j = 1;j<=num && (ll)i*prim[j]<=N;j++)
    {
      int t  = i*prim[j];
      vis[t] = 1;
      if(i%prim[j] == 0)
      {
        if(i/prim[j] % prim[j] == 0)
           dp[t] = dp[i]*prim[j];
        else
           dp[t] = dp[i/prim[j]]*(prim[j]-1)*(prim[j]-1);
        break;
      }
      else
      dp[t] = dp[i]*dp[prim[j]];
    }
  }
  for(int i = 1;i<=N;i++) dp[i]+=dp[i-1];
}
ll slove(ll n) //分块的思想去降低复杂度
{
  int l,r,t;
  ll ret = 0;
  for(l = 1;l*l<=n;l++)
  {
    t = n/l,ret += 1LL*t*t*(dp[l]-dp[l-1]);
  }
  for(t = n/l;l<=n;l=r+1,t--)
  {
    r = n/t;ret+=1LL*t*t*(dp[r]-dp[l-1]);
  }
  return ret;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;pre();
  while(t--)
  {
    ll n;cin>>n;
    cout<<slove(n)<<endl;
  }
  return 0;
}
