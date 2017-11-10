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
ll n,p;
ll quick(int x,int y)
{
  ll a = 1;
  x%=p;
  while(y)
  {
    if(y&1)
    a = (a*x) %p;
    x = (x*x) %p;
    y/=2;
  }
   return a;
}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>p;
    ll ans = 0;
    for(ll i = 0;i<n;i++)
    {
      ans = (ans+quick(n,gcd(n,i)))%p;
      //cout<<ans<<endl;
    }
    cout<<ans/n<<endl;
  }


  return 0;
}
