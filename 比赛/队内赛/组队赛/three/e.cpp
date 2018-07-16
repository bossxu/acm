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
ll quick(ll a, ll b, ll m)
{
  ll res = 1;
  while(b)
  {
    if(b&1)
      res = res*a%m;
    a = a*a%m;
    b/=2;
  }
  return res;
}
ll phi(ll n)
{
  ll ret=n;
  for(ll i=2;i*i<=n;i++)
   if(n%i==0)
   {
      ret=ret-ret/i;//先进行除法防止溢出(ret=ret*(1-1/p(i)))
      while(n%i==0)
        n/=i;
   }
  if(n>1)
        ret=ret-ret/n;
      return ret;
}
ll dfs(ll n, ll m)
{
  ll op=phi(m);
  //cout<<m<<" "<<phi(m)<<endl;
  //if(op==1)
  //   return 1;
  //cout<<n<<" "<<m<<endl;
  if(n == 1) return 1%m;
  if(m == 1) return 0;
  //ll op=phi(m);
  // op = phi(m);
  //cout<<n<<" "<<m<<endl;
  //if(op == 1) return 1;
  return quick(n%m,dfs(n-1,op),m);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m;
  while(cin>>n>>m)
  {
    //cout<<phi(m)<<endl;
    cout<<dfs(n,m)<<endl;
  }
  return 0;
}
