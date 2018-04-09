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
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int lpsDp(char *str, int n)
{
    int dp[1035][1035], tmp;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)  dp[i][i] = 1;

    for (int i = 1; i < n; ++i)
    {
        tmp = 0;
        //考虑所有连续的长度为i+1的子串，str[j....j+i]
        for (int j = 0; j + i < n; j++)
        {
            //如果首尾相同
            if (str[j] == str[j + i])
                tmp = dp[j + 1][j + i - 1] + 2;
            //如果首尾不同
            else
                tmp = max(dp[j + 1][j + i], dp[j][j + i - 1]);
            dp[j][j + i] = tmp;
        }
    }
    return dp[0][n - 1]; //返回字符串str[0...n-1]的最长回文子序列长度
}

int main()
{
  char s[1033];
  while(cin>>s)
  {
    for(int i = 0;i<strlen(s);i++)
    {
      if(s[i]>='A' && s[i]<='Z')
      {
        s[i] = 'a'+s[i]-'A';
      }
    }
    int res = lpsDp(s,strlen(s));
    cout<<strlen(s) - res<<endl;
  }
}
