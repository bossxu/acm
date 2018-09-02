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


int main()
{
  ll n,s1,s2,s3,s4;
  while(cin>>n>>s1>>s2>>s3>>s4)
  {
    ll ans = abs(s2-s4) + abs(s1-s3);
    if(ans == 0)
    {
      cout<<n/2<<endl;
    }
    else
    {
      ans = n-ans;
      if(ans<0)
      {
        cout<<0<<endl;
      }
      else
      {
        ans/=2;
        cout<<ans+1<<endl;
      }
    }
  }
  return 0;
}
