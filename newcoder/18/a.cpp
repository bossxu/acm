#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
#define clr(a,x) memset(a,x,sizeof(a))
const ll mod = 2000000000000000003;
int main()
{
  std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  ll n;
  while(t--)
  {
    cin>>n;
    ll ans = 1;
    while(n>4)
    {
      ans = ans*3%mod;
      n-=3;
    }
    ans=ans*n%mod;
    cout<<ans<<endl;
  }
  return 0;
}
