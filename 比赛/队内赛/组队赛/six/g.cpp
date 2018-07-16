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
ll shu[100005];
ll gcd(ll a, ll b)
{
  return b == 0?a:gcd(b,a%b);
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    ll gc,lcm;
    cin>>n>>gc>>lcm;

    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      if(shu[i]%gc) {ans++;shu[i] = 0;continue;}
    }
    if(n == 1)
    {
      if(gc == lcm)
      cout<<(shu[1] == gc?0:1)<<endl;
      else
      cout<<-1<<endl;
      continue;
    }
    if(lcm%gc)
    {
      cout<<-1<<endl;
      continue;
    }
    lcm/=gc;
    for(int i = 1;i<=n;i++)
    {
      if(!shu[i]) continue;
      shu[i]/=gc;
      if(lcm%shu[i]) {ans++;shu[i] = 0;}
    }
    int comgc = -1;
    int comlc = -1;
    for(int i = 1;i<=n;i++)
    {
      if(!shu[i]) continue;
      comgc = shu[i];
      comlc = shu[i];
      break;
    }
    for(int i = 1;i<=n;i++)
    {
      if(shu[i] == 0) continue;
      comgc = gcd(comgc,shu[i]);
      comlc = comlc*shu[i]/gcd(comlc,shu[i]);
      //cout<<" hello "<<comgc<<" "<<comlc<<endl;
    }
    int flag;
    if(comlc >0 && gcd(comgc,lcm/comlc) == 1)
    {
      flag = 1;
    }
    else
    {
      flag = 2;
    }
    if(comgc == 1 && comlc == lcm) flag = 0;
    if(ans>=2)
    {
      cout<<ans<<endl;
      //continue;
    }
    if(ans == 1)
    {
      if(flag == 0) cout<<1<<endl;
      if(flag == 1) cout<<1<<endl;
      if(flag == 2) cout<<2<<endl;
    }
    if(ans == 0)
    {
      cout<<flag<<endl;
    }
  }
  return 0;
}
