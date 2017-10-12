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
#define INF 0x3f3f3f3fconst
const int mod = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
char s[705];
int m[705];
ll dp[705][705][3][3];
// 很好的一道题,难的一批
//不过我也找到了状态转移方程的寻找
//首先二维时必须存在的 然后思考一下他对前面的有什么要求
//他对子区间的要求在于我要看下子区间的 左右括号的状态都要知道,不然根本无法进行
//所以这个状态的转移就需要有4维
//不过这个转移是真的厉害
void match()//模拟栈进行配对
{
  stack<int>ss;
  int n = strlen(s);
  for(int i = 0;i<n;i++)
  {
    if(s[i] == '(')
    ss.push(i);
    else
    {
      int l = ss.top();
      m[i] = l;
      m[l] = i;
      ss.pop();
    }
  }
}
void dfs(int a,int b)
{
  if(a+1 == b)
  {
    dp[a][b][1][0] = dp[a][b][0][1] = 1;
    dp[a][b][2][0] = dp[a][b][0][2] = 1;
    return ;
  }
  if(m[a] == b)
  {
    dfs(a+1,b-1);
    for(int i = 0;i<3;i++)
    {
      for(int j = 0;j<3;j++)
      {
        if(j!=1)
        dp[a][b][0][1] = (dp[a][b][0][1]+dp[a+1][b-1][i][j]) % mod;
        if(i!=1)
        dp[a][b][1][0] = (dp[a][b][1][0]+dp[a+1][b-1][i][j]) % mod;
        if(j!=2)
        dp[a][b][0][2] = (dp[a][b][0][2]+dp[a+1][b-1][i][j]) % mod;
        if(i!=2)
        dp[a][b][2][0] = (dp[a][b][2][0]+dp[a+1][b-1][i][j]) % mod;
      }
    }
    return ;
  }
    int t = m[a];
    dfs(a,t);
    dfs(t+1,b);
    for(int i = 0;i<3;i++)
    {
      for(int j = 0;j<3;j++)
      {
         for(int k = 0;k<3;k++)
         {
           for(int q = 0;q<3;q++)
           {
             if(!((k==1 && q==1) || (k==2 && q==2)))
               dp[a][b][i][j] = (dp[a][b][i][j] + (dp[a][t][i][k]*dp[t+1][b][q][j])%mod)%mod;
           }
         }
      }
    }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(scanf("%s",s)!=EOF)
  {
    getchar();
    int n = strlen(s);
    match();
    clr(dp,0);
    dfs(0,n-1);
    ll ans = 0;
    for(int i = 0;i<3;i++)
     for(int j =0;j<3;j++)
     {
       ans = (dp[0][n-1][i][j] + ans)%mod;
     }
     cout<<ans<<endl;
  }

  return 0;
}
