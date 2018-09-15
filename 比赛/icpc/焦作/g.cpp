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
char s[100005];
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%mod;
    a = a*a%mod;
    b>>=1;
  }
  return res;
}
int main()
{
  int t;
  ios_close;
  cin>>t;
  while(t--)
  {
    cin>>s;
    int len = strlen(s);
    ll ans = 0;
    for(int i = 0;i<len;i++)
    {
      ans = (ans*10+s[i]-'0')%(mod-1);
    }
    cout<<quick(2,ans-1)<<endl;
  }
  return 0;
}
