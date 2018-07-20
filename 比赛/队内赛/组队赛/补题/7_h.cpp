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
//hdu 6283
//线性递推的问题有点菜,当时想过用矩阵快速幂
//可见还是题见少了
//test 1 50阶的,用菜队的bm算法
// 测下板子有没有问题
// 可以说是神仙了
#define VI vector<int>
#define pb push_back
const int N = 1<<17;
ll res[N],base[N],_c[N],_md[N];
VI Md;
void mul(ll *a, ll *b, int k)
{
for (int i = 0; i < k + k; i++) _c[i] = 0;
for (int i = 0; i < k; i++)
if (a[i])
for (int j = 0; j < k; j++) _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
for (int i = k + k - 1; i >= k; i--)
if (_c[i])
for (int j = 0; j < Md.size(); j++) _c[i - k + Md[j]] = (_c[i - k + Md[j]]-_c[i]*_md[Md[j]] )%mod;
for (int i = 0; i < k; i++) a[i] = _c[i];
}
int solve(ll n, VI a, VI b)
{
ll ans = 0, pnt = 0;
int k = a.size();

for (int i = 0; i < k; i++) _md[k - 1 - i] = -a[i];
_md[k] = 1;
Md.clear();
for (int i = 0; i < k; i++)
if (_md[i] != 0) Md.push_back(i);
for (int i = 0; i < k; i++) res[i] = base[i] = 0;
res[0] = 1;
while ((1LL << pnt) <= n) pnt++;
for (int p = pnt; p >= 0; p--)
{
mul(res, res, k);
if ((n >> p) & 1)
{
for (int i = k - 1; i >= 0; i--) res[i + 1] = res[i];
res[0] = 0;
for (int j = 0; j < Md.size(); j++) res[Md[j]] = (res[Md[j]] - res[k] *_md[Md[j]])%mod;
}
}
for (int i = 0; i < k; i++) ans = (ans + res[i] * b[i]) % mod;
if (ans < 0) ans += mod;
return ans;
}
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b){ if(b&1) res = res*a%mod; a = a*a%mod;b/=2;}
  return res;
}
VI BM(VI s)
{
VI C(1, 1), B(1, 1);
int L = 0, m = 1, b = 1;
for (int n = 0; n < s.size(); n++)
{
ll d = 0;
for (int i = 0; i <= L; i++) d = (d + (ll)C[i] * s[n - i]) % mod;
if (d == 0)
++m;
else if (2 * L <= n)
{
VI T = C;
ll c = mod - d * quick(b, mod - 2) % mod;
while (C.size() < B.size() + m) C.pb(0);
for (int i = 0; i < B.size(); i++) C[i + m] = (C[i + m] + c * B[i]) % mod;
L = n + 1 - L, B = T, b = d, m = 1;
}
else
{
ll c = mod - d * quick(b, mod - 2) % mod;
while (C.size() < B.size() + m) C.pb(0);
for (int i = 0; i < B.size(); i++) C[i + m] = (C[i + m] + c * B[i]) % mod;
++m;
}
}
return C;
}
int gao(VI a, ll n)
{
VI c = BM(a);
c.erase(c.begin());
for (int i = 0; i < c.size(); i++) c[i] = (mod - c[i]) % mod;
return solve(n, c, VI(a.begin(), a.begin() + c.size()));
}
ll a[60];
ll c[60];
ll f[105];
ll dp[105];
vector<int>q;
int n;
ll m;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(cin>>n>>m)
  {
    q.clear();
    for(int i = 1;i<=n;i++)
    {
      cin>>a[i];
    }
    for(int i = 1;i<=n;i++)
    {
      cin>>c[i];
    }
    clr(f,0);
    clr(dp,0);
    for(int i = 1;i<=2*n;i++)
    {
      if(i<=n)
      {
        f[i] = a[i];
        continue;
      }
      for(int j = 1;j<=n;j++)
      {
        f[i] =( f[i] + c[j]*f[i-j] )%mod;
      }
    }
    dp[1] = f[1];
    dp[0] = 1;
    q.push_back(dp[1]);
    for(int i = 2;i<=2*n;i++)
    {
      for(int j = 1;j<=i;j++)
      {
        dp[i] = dp[i] + f[j]*dp[i-j];
        dp[i]%=mod;
      }
      q.push_back(dp[i]);
    }
    cout<<gao(q,m-1)<<endl;
  }
  return 0;
}
