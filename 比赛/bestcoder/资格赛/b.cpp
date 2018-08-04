#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
char s[100005];
int dp[100005][26];
int main()
{
  int t;
  cin>>t;
  int tot = 0;
  while(t--)
  {
    int n,q;
    clr(dp,0);
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for(int i = 1;i<=n;i++)
    {
      dp[i][s[i]-'A']++;
      for(int j = 0;j<26;j++)
      {
        dp[i][j] += dp[i-1][j];
      }
    }
    printf("Case #%d:\n",++tot);
    for(int i = 1;i<=q;i++)
    {
      int l,r;
      scanf("%d%d",&l,&r);
      for(int j = 0;j<26;j++)
      {
        int ans = dp[r][j] - dp[l-1][j];
        if(ans > 0)
        {
          printf("%d\n",ans);
          break;
        }
      }
    }
  }
  return 0;
}
