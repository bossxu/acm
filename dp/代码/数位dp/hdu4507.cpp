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
int shu[25];
struct Node{
  ll cnt;
  ll sum;
  ll bigsum;
  Node() {cnt=-1;sum=bigsum=0;}
  Node(ll cnt,ll sum,ll bigsum):cnt(cnt),sum(sum),bigsum(bigsum) {}
}dp[20][10][10];
ll cun[20];
Node dfs(int len,int st,int yu,int flag)
{
   if(len<0) return st!=0 && yu!=0?Node(1,0,0):Node(0,0,0);
   if(!flag && ~dp[len][st][yu].cnt) return dp[len][st][yu];
   int Max = flag?shu[len]:9;
   Node ans; ans.cnt=0;
   for(int i = 0;i<=Max;i++)
   {
     if(i == 7) continue;
     Node next = dfs(len-1,(st+i)%7,(yu*10+i)%7,flag && i==Max);
     ans.cnt+=next.cnt;
     ans.cnt%=mod;
     ans.sum+=(next.sum+(next.cnt*cun[len]*i%mod))%mod;
     ans.sum%=mod;
     ans.bigsum+=(next.bigsum + (next.sum*cun[len])%mod*2*i%mod)%mod;
     ans.bigsum%=mod;
     ans.bigsum+=(cun[len]*i*i%mod)*(cun[len]*next.cnt%mod)%mod;
     ans.bigsum%=mod;
   }
   if(!flag) dp[len][st][yu] = ans;
   return ans;
}
ll slove(ll x)
{
  int co = 0;
  while(x)
  {
    shu[co++] = x%10;
    x/=10;
  }
  return dfs(co-1,0,0,1).bigsum%mod;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  cun[0] = 1;
  for(int i = 1;i<=20;i++)
  {
    cun[i] = cun[i-1] * 10 % mod;
  }
  while(t--)
  {
    ll a,b;
    cin>>a>>b;
    ll ans = slove(b) - slove(a-1);
    ans = (ans+mod)%mod;
    cout<<ans<<endl;
  }
  return 0;
}
