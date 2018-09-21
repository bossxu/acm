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
const int N = 1e5+6;
int num[N+5];
int prim[N+6];
int mark[N+6];
int cnt;
void init()
{
  cnt=0;
  for (int i=2 ; i<N ; ++i)
  {
      if (!mark[i])
          prim[cnt++]=i;
      for (int j=0 ; j<cnt && i*prim[j]<N ; ++j)
      {
          mark[i*prim[j]]=1;
          if (!(i%prim[j]))
              break;
      }
  }
}
int main()
{
  ios_close;
  int t;
  init();
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    unsigned long long op = n;
    unsigned long long ans = 1;

  }
  return 0;
}
