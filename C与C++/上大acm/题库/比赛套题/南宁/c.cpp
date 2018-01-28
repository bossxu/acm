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
const int maxn  = 1e5+2;
int l[2*maxn],shu[2*maxn],n,m[2*maxn],ans;
char ls;
inline int read()//加快输入输出
{
    char k=0;ls=getchar();for(;ls<'0'||ls>'9';k=ls,ls=getchar());
    int x=0;for(;ls>='0'&&ls<='9';ls=getchar())x=x*10+ls-'0';
    if(k=='-')x=0-x;return x;
}
int dp[maxn];
void LIS()
{
    int i,j;
    m[1] = shu[1];
    dp[shu[1]] = l[1];
    ans = shu[1];
    for(i = 2; i <= n; i++)
    {
      for( j = ans;j>=0;j--)
      {
        if(j == 0)
        {
          dp[shu[i]] = min(dp[shu[i]],l[i]);
        }
        if(l[i]>=dp[j])
        {
          dp[j+shu[i]]=min(l[i],dp[j+shu[i]]);
          ans = max(ans,j+shu[i]);
        }
      }
    }
    return ;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int a,i;
  clr(l,0);
  clr(shu,0);
  clr(dp,INF);
  ls=' ';
  for( i =1;ls==' ';i++)
  {
    a = read();
    if(a>=10000)
    {
      shu[i] = 5;
      l[i] = a-10000;
    }
    else if(a<0)
    {
      shu[i] = 0;
      l[i] = a;
    }
    else
    {
      shu[i] = 1;
      l[i] = a;
    }
  }
  n = i-1;
  LIS();
  cout<<ans<<endl;
  getchar();
  return 0;
}
