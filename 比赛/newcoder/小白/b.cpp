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
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
char s[200005];
int dp[5];
const ll mod = 2000120420010122;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>s)
  {
    clr(dp,0);
    int len = strlen(s);
    for(int i = 0;i<len;i++)
    {
      if(s[i] == 'C' || s[i] == 'c') dp[1]++;
      if(s[i] == 'w' || s[i] == 'W') dp[2] = dp[1]+dp[2]%mod;
      if(s[i] == 'b' || s[i] == 'B' ) dp[3] = dp[2]+dp[3]%mod;
      if(s[i] == 'c' || s[i] == 'C') dp[4] = dp[4]+dp[3]%mod;
    }
    cout<<dp[4]<<endl;
  }
  return 0;
}
