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
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char s[105];
    int a[105],dp[105][105];
    while(scanf("%s",s)!=EOF)
    {
      getchar();
      //printf("%s\n",s);
      if(s[0] == 'e') break;
      for(int i=0;i<strlen(s);i++)
      {
        if(s[i]=='(') a[i+1]=1;
        if(s[i]==')') a[i+1]=-1;
        if(s[i]=='[') a[i+1]=2;
        if(s[i]==']') a[i+1]=-2;
      }
      int n =strlen(s);
      clr(dp,0);
      for(int j=1;j<=n+1;j++)
      {
        for(int i=0;i+j<=n+1;i++)
        {
          if(a[i]>0 && a[i]+a[i+j]==0)
          dp[i][i+j] = 2;
          for(int k =i+1+1;k<i+j && (i+1)<(i+j-1);k++)
          {
            dp[i+1][i+j-1] = max(dp[i+1][i+j-1],dp[i+1][k]+dp[k][i+j-1]);
          }
          dp[i][i+j] +=dp[i+1][i+j-1];
        }
      }
      cout<<dp[0][n+1]<<endl;
    }
    return 0;
}
