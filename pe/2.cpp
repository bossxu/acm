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
ll dp[1005];
int main()
{
  //freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  dp[1] = 1;
  dp[2] = 2;
  int tot = 3;
  ll sum = 2;
  while(true)
  {
    dp[tot] = dp[tot-1] + dp[tot-2];
    if(dp[tot] > 4000000)
    break;
    if(dp[tot]%2 == 0) {sum+=dp[tot];}
    tot++;
  }
  cout<<sum<<endl;
  return 0;
}
