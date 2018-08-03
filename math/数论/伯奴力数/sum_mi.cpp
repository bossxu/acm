#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
//这里是用伯奴力数来解决自然数幂的问题
const int maxn = 2005;
ll C[maxn][maxn],b[maxn],Inv[maxn],tmp;
//需要预处理组合数，伯努力数，逆元,在o(n^2）的范围里解决这个问题
void init()
{
  C[0][0] = 1;//预处理组合数
  for(int i = 1;i<maxn;i++)
  {
    C[i][0] = 1;
    for(int j = 1;j<=i;j++) C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
  }
  Inv[1] = 1;//预处理逆元
  for(int i = 2;i<maxn;i++) Inv[i] = Inv[mod%i]*(mod-mod/i)%mod;
  b[0] = 1;
  for(int i = 1;i<maxn;i++)//预处理伯努力数
  {
    b[i] = 0;
    for(int k = 0 ;k<i;k++) b[i] = (b[i] + C[i+1][k]*b[k] % mod ) % mod;
    b[i] = (b[i]*(-Inv[i+1])%mod+mod)%mod;
  }
}
ll slove(ll n,ll k)//处理的是前n项k次幂的情况
{
  n++;n%=mod;tmp = n;
  ll ans = 0;
  for(int i = 1;i<=k+1;i++)
  {
    ans = (ans+(C[k+1][i]*b[k+1-i]%mod)*n%mod)%mod;
    n = n*tmp%mod;
  }
  ans = ans*Inv[k+1]%mod;
  return ans;
}
int main()
{
  int n,k;
  init();
  while(cin>>n>>k)
  {
    cout<<slove(n,k)<<endl;
  }
  return 0;
}
