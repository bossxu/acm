#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
// 在低于线性的复杂度里求前n个正整数的约数之和
// 主要解决方案在于分段加速，枚举因子
ll slove(ll n)
{
  // i*floor(n/i)
  ll ans = 0;
  ll i;
  for(i = 1;i*i<=n;i++)
  {
    ans += i*(n/i);
    ll st = n/i;
    ll end = n/(i+1)+1;
    ans +=(st-end+1)*(end+st)/2*i;
  }
  i--;
  if(i*i == n)
  {
    ans -= i*i;
  }
  return ans;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n;
  while(cin>>n)
  {
    cout<<slove(n)<<endl;
  }
  return 0;
}
