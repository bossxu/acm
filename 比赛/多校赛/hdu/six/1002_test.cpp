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

ll f[105];

void init()
{
  f[0] = 0;
  f[1] = 1;
  for(int i = 2;i<=100;i++)
  {
    f[i] = f[i-1] + f[i-2];
    //if(f[i]>=mod) cout<<i<<endl;
  }
}
ll quick(ll a,ll b,ll op)
{
  ll res = 1;
  while(b)
  {
    if(b&1) res = res*a%op;
    a = a*a%op;
    b>>=1;
  }
  return res;
}
int main()
{
  init();
  for(int i  = 3;i<=99;i+=2)
  {
    cout<<i<<": "<<endl;
    for(int j = 1;j<=30;j++)
    {
      if(quick(2,f[j],i) == 1)
      cout<<j<<" ";
    }
    cout<<endl;
  }
  int t;
  while(cin>>t)
  {

  }
  return 0;
}
