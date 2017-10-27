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
//置换群的概念
int gcd(int a,int b)
{
  return a%b==0?b:gcd(b,a%b);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int a,b;
  ll dp[52];
  while(cin>>a>>b)
  {
    dp[0] = 1;
    for(int i = 1;i<=a+1;i++)
    {
      dp[i] = dp[i-1] * b;
    }
    ll ans=0,sum=0;
    for(int i = 0;i<a;i++)
    {
      ans += dp[gcd(i,a)];
      sum += dp[gcd(i,a)];
    }
    if(a%2 == 1)
    sum += a*dp[(a-1)/2+1];
    else
    sum += a/2*(dp[(a/2)]+dp[a/2+1]);
    cout<<ans/a<<" ";
    cout<<sum/a/2<<endl;
  }

  return 0;
}
