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
const int mod = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  ll dp[110];
  int a[110];
  int n;
  while(cin>>n){
      for(int i=1;i<=n;i++)
        cin>>a[i];
        ll ans=0;
        clr(dp,0);
     for(int i=1;i<=n;i++)
        {
         dp[i]=1;
         for(int j=1;j<i;j++){
            if((double)j*log(a[i]*1.0)>(double)i*log(a[j]*1.0)){
              dp[i]=(dp[j]+dp[i])%mod;
            }
          }
            ans=(ans+dp[i])%mod;
          }
   cout<<ans%mod<<endl;
  }
  return 0;
}
