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
#define INF 0x7fffffff
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
#define MAXN 1000005
int shu[MAXN];
int dp[MAXN];
int mmax[MAXN];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n,m;
  while(cin>>m>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      dp[i] = 0;
      mmax[i] = 0;
    }
    int mmmax;
    dp[0] = 0;
    mmax[0] = 0;
    for(int i = 1;i<=m;i++)
    {
       mmmax = -INF;
      for(int j = i;j<=n;j++)
      {
        dp[j] = max(dp[j-1],mmax[j-1])+shu[j];
        mmax[j-1] = mmmax;
        mmmax = max(mmmax, dp[j]);
      }
    }
    cout<<mmmax<<endl;

  }
  return 0;
}
