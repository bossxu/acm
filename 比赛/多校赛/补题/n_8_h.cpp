#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":";
const int mod = 1e9+7;
ll rev = (mod+1)/2;
const double eps = 1e-6;

//fwd 优化多项式的一种操作。
const int N = 1<<19;
ll shu[21][N+10];
void FWT(ll a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                ll x=a[i+j],y=a[i+j+d];
                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
            }
}

void UFWT(ll a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                ll x=a[i+j],y=a[i+j+d];
                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
            }
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    clr(shu,0);
    ll res = 0;
    int x;
    for(int i = 0;i<n;i++)
    {
      cin>>x;
      shu[0][x] = 1;
      res^=x;
    }
    if(res == 0)
    {
      cout<<n<<endl;
      continue;
    }
    if(shu[0][res])
    {
      cout<<n-1<<endl;
      continue;
    }
    shu[0][0] = 1;
    FWT(shu[0],N);
    for(int i = 1;i<=19;i++)
    {
      for(int j = 0;j<N;j++)
      {
        shu[i][j] = shu[0][j]*shu[i-1][j]%mod;
      }
    }
    int ans = 0;
    for(int i = 1;i<=19;i++)
    {
      UFWT(shu[i],N);
      if(shu[i][res])
      {
        //cout<<shu[i][res]<<endl;
        ans = n-i-1;
        break;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
