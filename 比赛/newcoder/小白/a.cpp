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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
char s[200005];
int dp[30];
void init()
{
  for(int i = 0;i<=3;i++) dp[i] = 0;
  for(int i = 4;i<=7;i++) dp[i] = 4;
  for(int i = 8;i<=13;i++) dp[i] = 8;
  for(int i = 14;i<=19;i++) dp[i] = 14;
  for(int i =20;i<=23;i++) dp[i] = 20;
  for(int i = 24;i<=25;i++) dp[i] = 24;

}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);a
  //std::ios::sync_with_stdio(false);
  init();
  while(scanf("%s",s) == 1)
  {
    int k = strlen(s);
    for(int i = 0;i<k;i++)
    {
      putchar('a'+dp[s[i]-'a']);
    }
    cout<<endl;
  }
  return 0;
}
