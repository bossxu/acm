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
char s[22];
int dp[22][2];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    clr(dp,0);
    for(int i = 1;i<=n;i++)
    {
      cin>>s;
      for(int j = 0;j<m;j++)
      {
        dp[j][s[j]-'0']++;
      }
    }
    for(int i = 0;i<m;i++)
    {
      if(dp[i][1]>dp[i][0])
      {
        cout<<'0';
      }
      else
      cout<<"1";
    }
    cout<<endl;
  }
  return 0;
}
