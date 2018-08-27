#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
ll shu[200005];
map<ll,int>dp[20];
ll bas[20];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,k;
  bas[0] = 1;
  while(cin>>n>>k)
  {
    for(int i = 1;i<=12;i++) dp[i].clear(),bas[i] = bas[i-1]*10%k;
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      int len = 0;
      ll op = shu[i];
      while(op) {len++,op/=10;}
      //cout<<len<<endl;
      if((shu[i]+shu[i]*bas[len])%k == 0) ans--;

      dp[len][shu[i]%k]++;
    }
    //cout<<ans<<endl;
    for(int i = 1;i<=n;i++)
    {
      ll op = shu[i]%k;
      for(int j = 1;j<12;j++)
      {
        ll ko = (op*bas[j])%k;
        //cout<<i<<" "<<ko<<endl;
        ans += dp[j][(k-ko)%k];
      }
      //cout<<ans<<endl;
    }
    //ans++;
    cout<<ans<<endl;
  }
  return 0;
}
