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
const int mod = 2520;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
//好题,难的一批
ll dp[20][50][2550];
int shu[20];
int Hash[2550];
ll gcd(ll a,ll b)
{ return b?gcd(b,a%b):a;}

ll dfs(int len,int num,int lcm,bool flag)
{
  if(len == 0) return num%lcm == 0;
  if(!flag && dp[len][Hash[lcm]][num]!=-1) return dp[len][Hash[lcm]][num];
  ll ans = 0;
  int end = flag?shu[len]:9;
  for(int i = 0;i<=end;i++)
  {
    ans += dfs(len-1,(num*10+i)%mod,i?lcm*i/gcd(lcm,i):lcm,flag && i==end);
  }
  if(!flag) dp[len][Hash[lcm]][num] = ans;
  return ans;
}
ll init(ll n)
{
  int i = 1;
  while(n)
  {
    shu[i++] = n%10;
    n/=10;
  }
  return  dfs(i-1,0,1,1);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  for(int cot=0,i=1;i<=mod;i++)
  {
    if(mod%i==0)
     Hash[i] = cot++;
  }
  clr(dp,-1);
  while(t--)
  {
    ll li,ri;
    cin>>li>>ri;
    cout<<init(ri)-init(li-1)<<endl;
  }
  return 0;
}
