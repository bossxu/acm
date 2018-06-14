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
ll dp[1006];
void init()
{
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3;i<=1000;i++)
  {
    dp[i] = dp[i-1]+dp[i-2];
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  init();
  while(t--)
  {
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
  }
  return 0;
}
