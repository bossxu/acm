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
//学会分析问题,把问题片面化
//缩小化,学会思考,学会懂得第一步干什么,第二步干什么
int prime[25]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}
ll dp[105][105];
ll large[105];
void init()
{
  clr(dp,0);
  for(int i = 1;i<=100;i++) dp[i][1] = i;
  for(int i = 2;i<=100;i++)
  {
    for(int j = 2;j<=i;j++)
    {
      for(int k = 1;k<i && i-k>=j-1;k++)
      {
        dp[i][j] = max(dp[i-k][j-1]*k/gcd(dp[i-k][j-1],k),dp[i][j]);
      }
    }
  }
  clr(large,0);
  for(int i=1;i<=100;i++)
   for(int j=1;j<=i;j++)
    large[i] = max(large[i],dp[i][j]);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  init();
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    cout<<large[n];
    int a[105];
    int tot = 0;
    ll k = large[n];
    int sum = 0;
    for(int i = 0;i<25;i++)
    {
      if(k % prime[i]) continue;
      a[tot] = 1;
      while(k % prime[i]==0)
      {
        a[tot] *= prime[i];
        k/=prime[i];
      }
      sum+=a[tot];
      tot++;
    }
   sort(a,a+tot);
   for(int i = 1;i<=n-sum;i++)
   {
     cout<<" "<<i;
   }
   int temp = n-sum;
   for(int i = 0;i<tot;i++)
   {
     for(int j = 2;j<=a[i];j++)
      {
        cout<<" ";
        cout<<temp+j;
      }
      cout<<" "<<temp+1;
      temp += a[i];
   }
   cout<<endl;
  }
  return 0;
}
