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
const int maxn = 1<<18;
// 马个鸡 第一次看到有人用fwt 去处理特殊矩阵，可以说真的是很神奇。
// 处理万这个，可以变成一个卷积的形式真的没有想到，真的厉害。
ll quick(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1)
    res = res * a%mod;
    a = a*a%mod;
    b>>=1;
  }
  return res;
}
ll rev = (1+mod)/2;
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
ll a[maxn+7];
ll b[maxn+7];

int main()
{
  ios_close;
  int n;
  while(cin>>n)
  {
    clr(a,0);
    clr(b,0);
    for(int i = 0;i<n;i++)
    {
      cin>>a[i];
    }
    for(int i = 0;i<n;i++)
    {
      cin>>b[i];
    }
    FWT(a,n);
    FWT(b,n);
    for(int i = 0;i<n;i++)
    {
      a[i] = b[i]*quick(a[i],mod-2)%mod;
    }
    UFWT(a,n);
    for(int i = 0;i<n;i++)
    {
      cout<<a[i]<<endl;
    }

  }
  return 0;
}
