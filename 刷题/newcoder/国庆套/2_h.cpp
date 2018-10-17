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
const int N = 1e5+5;
double dp[N];
// 算单点贡献，也就是说我每次拿一张牌它出现的期望是什么。
int main()
{
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  int t;scanf("%d",&t);
  int tot = 0;
  while(t--)
  {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    dp[k] = 0;
    for(int i = k-1; i>=0;i--)
    {
      double p = 1.0*(m-i)/(n-i);
      dp[i] = dp[i+1]+1.0/p;
    }
    printf("Case #%d: %.8lf\n",++tot,dp[0]);
  }
  return 0;
}
