#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 998244353;
const double eps = 1e-6;
const int N = 1e6+5;
// 简你妈的组合排列，超级难好不好
// 他的思路是这样的，首先看最后的状态，这里取决的是一共用到了多少有用的数字
// 数字选定其实和前面的顺序是有关的，这个可以看出来
// 选完有效数字后还要去算，前面不同的东西，然后我看了别人的博客，就是说，我们还要算出来，每个数字第一次出现的情况，这个是关键
// 因为开头都是确定的，所以这里的是(n-1,k-1)
// 真的想不到，太菜了，不过这是一种思考的方式，它深入的是对于每一个状态所得到的结论。直接看最后的那个，再去判断前面的情况。
// 还是要广点思考的方向
ll inv[N];
void init()
{
  inv[0] = inv[1] = 1;
  for(int i = 2;i<=1000000;i++)
  inv[i]=(mod-mod/i)*inv[mod%i]%mod;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  int tot = 0;
  init();
  cin>>t;
  while(t--)
  {
    cout<<"Case #"<<++tot<<": ";
    ll n,m;
    cin>>n>>m;
    ll ans = 0;
    ll sum = 1;
    int len = min(m,n);
    for(int i = 1;i<=len;i++)
    {
      sum = 1LL*sum*((m-i+1)%mod)%mod;
      if(i>1)
      {
        sum = (1LL*sum*((n-i+1)%mod)%mod)*inv[i-1]%mod;
      }
      ans = (ans+sum)%mod;
    }
    cout<<ans<<endl;
  }
  return 0;
}
