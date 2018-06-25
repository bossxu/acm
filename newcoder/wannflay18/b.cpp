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
char s[1000010];
const int mod = 1e9+7;
ll quick(ll a,ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b&1)
    {
      ans = ans*a%mod;
    }
    a = a*a%mod;
    b/=2;
  }
  return ans;
}
int main()
{
  std::ios::sync_with_stdio(false);
  ll q;
  while(cin>>q)
  {
    cin>>s;
    ll ans = 0;
    int len = strlen(s);
    for(int i = 0;i<len;i++)
    {
      ans = (ans*10+s[i]-'0')%(mod-1);
    }
    //cout<<q<<endl;
    ll p = 10000-q;
    ll fenzi = quick((ll)10000,ans) - quick(p-q,ans);
    fenzi=(fenzi+mod)%mod;
    ll fenmu = quick((ll)10000,ans)*2%mod;
    fenmu = quick(fenmu,mod-2);
    cout<<fenzi*fenmu%mod<<endl;
  }
  return 0;
}
