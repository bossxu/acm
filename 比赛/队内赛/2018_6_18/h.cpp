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
char s[5005];
ll dp[5005][3];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  //std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)
  {
    scanf("%s",s);
    //cout<<s<<endl;
    int n = strlen(s);
    clr(dp,0);
    dp[0][0] = 0;
    dp[0][1]=dp[0][2]=0;
    for(int i = 0;i<n;i++)
    {
        int add = s[i]-'0';
        if(add)
        {
          dp[i][add%3] += 1;
        }
        for(int j = 0;j<=2;j++)
        {
          dp[i][(j+add)%3] = (dp[i][(j+add)%3]+dp[i-1][j]+dp[i-1][(j+add)%3])%mod;

        }
      // //  cout<<i<<"---"<<endl;
      //   for(int j = 0;j<=2;j++)
      //   {
      //     cout<<j<<" "<<dp[i][j]<<endl;
      //   }
    }
    cout<<dp[n-1][0]<<endl;
  }
  return 0;
}
