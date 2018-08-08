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

char s[100005];
int dp[100005][10];
int sta[100005][10];
int num[10];
int main()
{
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    clr(num,0);
    clr(dp,0);
    clr(sta,0);
    cin>>n>>s+1;
    int maxn = 0;
    for(int i = n;i>=1;i--) //求区间的变化的情况
    {
      int st = s[i]-'0';
      num[st] = max(num[st],i);
      for(int j = st;j>=0;j--)
      {
        dp[i][j] = num[j];
      }
    }
    for(int i = 1 ;i<=n;i++)
    {
      int st = s[i]-'0';
      for(int j = st;)
    }

  }
  return 0;
}
