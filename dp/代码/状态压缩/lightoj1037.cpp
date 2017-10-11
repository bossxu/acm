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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int map[20][20];
int dp[1<<16];
int n;
int hea[25];
//思维不能=太过拘泥,要想的开一点
// 首先什么可以压缩 ,压缩的目的在于什么
//什么小,什么是一个集合,可以由不同的状态转移过来,还有压缩的方向一般为2个
// 是 还是 不是 这个是可以做状态的目标
void solve()
{
   for(int i = 0;i <(1<<n);i++)
   {
     for(int j = 0;j<n;j++)
     {
       if(i & (1<<j))
        continue;
       int t =hea[j];
       for(int k =0;k<n;k++)
       {
         if((i & (1<<k)) && map[k][j] != 0)
         {
           int m = hea[j] / map[k][j];
           t = min((hea[j] % map[k][j]) ? m+1 : m,t);
         }
       }
       dp[i|(1<<j)] = min(dp[i]+t,dp[i|(1<<j)]);
     }
   }
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  int co = 0;
  while(t--)
  {
    clr(dp,INF);
    dp[0] = 0;
    cin>>n;
    for(int i = 0;i<n;i++)
    cin >> hea[i];
    char shu[20][20];
    for(int i = 0;i<n;i++)
     scanf("%s",shu[i]);
    for(int i = 0;i<n;i++)
     for(int j = 0;j<n;j++)
      map[i][j] = shu[i][j] - '0';
     solve();
    printf("Case %d: %d\n",++co,dp[(1<<n)-1]);
  }
  return 0;
}
