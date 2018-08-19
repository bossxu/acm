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
// 这题真的是纯粹的数学不知道了
//我们这里因为处理的东西不知道 ，我们这里处理的东西无法解决，所以，
//大老们就把我们处理不了的东西，进行了转化，变成了，一个可以进行预处理的东西。
//他把自然数下的组合数学扩展到了整数域下进行了求解。
//我日，真的太修了。
ll inv[205];
ll tree[42][100005];
void init()
{
  inv[1] = inv[0] = 1;
  for(int i = 2;i<=200;i++)
  {
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  }
}
int lowbit(int t)
{
  return t&(-t);
}
int n;
void add(int st,int x,ll y)
{
  for(int i=x;i<=n;i+=lowbit(i))
  (tree[st][i]+=y)%=mod;
}
ll getsum(int st,int x)
{
  ll ans=0;
  for(int i=x;i>0;i-=lowbit(i))
    (ans+=tree[st][i])%=mod;
  return ans;
}
int main()
{
  int m,k;
  init();
  while(cin>>n>>m>>k)
  {
    k-=1;
    for(int i = 1;i<=m;i++)
    {
      int op;
      int x,y;
      cin>>op;
      if(op == 0)
      {
        cin>>x>>y;
        ll u = 1;
        for(int j = 0;j<=k;j++)
        {
          add(j,x,y*u%mod);
          u = u*(k-x-j)%mod*inv[j+1]%mod;
          (u+=mod)%=mod;
        }
      }
      else
      {
        cin>>x;
        ll ans = 0;
        ll u = 1;
        for(int j = 0;j<=k;j++)
        {
          ans = (ans + u*getsum(k-j,x))%mod;
          u = u*(x-j)%mod*inv[j+1]%mod;
        }
        cout<<ans<<endl;
      }
    }
  }
  return 0;
}
