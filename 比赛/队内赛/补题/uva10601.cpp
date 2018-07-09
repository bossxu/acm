#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
//带限制的polay 新知识点get
//polay的定理要求的是每个循环节的所有点的颜色是一样的
//我需要深入理解每个定理的使用条件
int cnt[7];
int dp[7];
ll C[15][15];
void init()
{
  C[0][0] = 1;
  for(int i = 1;i<=12;i++)
  {
    C[i][0] = 1;C[i][i] = 1;
    for(int j = 1;j<i;j++)
    {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
}
ll slove(int k)
{
  int n = 0;
  for(int i = 1;i<=6;i++) cnt[i] = dp[i];
  for(int i = 1;i<=6;i++)
  {
    if(cnt[i]%k == 0)
    {
      cnt[i]/=k;
      n+=cnt[i];
    }
    else
    return 0;
  }
  ll res = 1;
  for(int i = 1;i<=6;i++)
  {
    res*=C[n][cnt[i]];
    n-=cnt[i];
  }
  return res;
}
ll slove_2(int k)
{
  int n = 0;
  //for(int i = 1;i<=6;i++) cnt[i] = dp[i];
  for(int i = 1;i<=6;i++)
  {
    if(cnt[i]%k == 0)
    {
      cnt[i]/=k;
      n+=cnt[i];
    }
    else
    return 0;
  }
  ll res = 1;
  for(int i = 1;i<=6;i++)
  {
    res*=C[n][cnt[i]];
    n-=cnt[i];
  }
  return res;
}
ll dian_slove()
{
  return 4*2*slove(3);
}
ll mian_slove()
{
  return 3*slove(2)+6*slove(4);
}
ll still_slove()
{
  return slove(1);
}
ll bian_slove()
{
  ll ans = 0;
  for(int i = 1;i<=6;i++)
  {
    for(int j = 1;j<=6;j++)
    {
      for(int  k = 1;k<=6;k++) cnt[k] = dp[k];
      cnt[i]--;cnt[j]--;
      if(cnt[i]<0  ||  cnt[j]<0) continue;
      ans += 6*slove_2(2);
    }
  }
  return ans;
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int t;
  cin>>t;
  while(t--)
  {
    clr(dp,0);
    for(int i = 1;i<=12;i++)
    {
      int op;
      cin>>op;
      dp[op]++;
    }
    ll ans = 0;
  //  cout<<still_slove()<<endl;
    ans += still_slove() + bian_slove() + dian_slove() + mian_slove();
    cout<<ans/24<<endl;
  }
  return 0;
}
