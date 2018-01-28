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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ll dp[30];
  dp[1] = 1;
  dp[0] = 1;
  for(int i = 2;i<=30;i++)
  {
    dp[i] = dp[i-1]*i;
  }
  while(true)
  {
    cout<<"cin n"<<endl;
    int n ;
    cin>>n;
    cout<<"the a's p"<<endl;
    double p;
    cin>>p;
    double shu[30];
    clr(shu,1);
    for(int i = 0;i<=n;i++)
    {
      double c=1;
      for(int j =0;j<i;j++)
      {
        c *= p;
      }
      for(int k = i+1;k<=n;k++)
      {
        c*=(1-p);
      }
      shu[i] = c*((dp[n]/dp[n-i])/dp[i]);
    }
    int z;
    while(true)
    {
      cin>>z;
      cout<<shu[z]<<endl;
    }
  }
  return 0;
}
