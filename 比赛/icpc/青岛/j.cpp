#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
ll gcd(ll a,ll b)
{
  return b == 0?a:gcd(b,a%b);
}
vector<ll>q;
int main()
{
  int t;scanf("%d",&t);
  while(t--)
  {
    ll a,b,c,d,v,t;
    scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&v,&t);
    ll Lcm = a/gcd(a,c)*c;
    q.clear();
    for(ll i = 0,j = 0;!(i==Lcm && j ==Lcm);)
    {
      if(i > j) j+=c;
      else i+=a;
      q.pb(min(i,j));
    }
    sort(q.begin(),q.end());int len = q.size();
    ll op = 0;
    for(int i = 1;i<len;i++)
    {
      //cout<<q[i]<<" ";
      if(q[i] - q[i-1] > v) op++;
    }
    // cout<<endl;
    ll ci = t/Lcm;
    ll all = (t/a)*b + (t/c)*d + b + d -1;
    ci *= op;
    all -= ci;
    t %= Lcm;
    for(int i = 1;q[i]<=t;i++)
    {
      if(q[i] - q[i-1] > v) all--;
    }
    printf("%lld\n",all);
  }
  return 0;
}
