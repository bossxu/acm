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
int main()
{
  int dp[100];
  char s[1005];
  dp[1] = 1;
  dp[2] = 1;
  for(int i = 1;i<=1000;i++)
  {
    s[i] = 'o';
  }
  s[1] = 'O';
  for(int i = 3;i<=100;i++)
  {
    dp[i] = dp[i-1]+dp[i-2];
    if(dp[i]>1000) break;
    s[dp[i]] = 'O';
  }
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cout<<s[i];
    }
    cout<<endl;
  }
  return 0;
}
