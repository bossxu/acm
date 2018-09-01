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
int shu[30];
int main()
{
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    clr(shu,0);
    ll ans = 0;
    int op;
    if(n == 1)
    {
      cin>>op;
      cout<<op<<endl;
      continue;
    }
    for(int i = 1;i<=n;i++)
    {
      cin>>op;
      for(int j = 0;j<23;j++)
      {
        if(op & (1<<j))
        {
          shu[j]++;
        }
      }
    }
    for(int i = 0;i<23;i++)
    {
      ans += 1LL*(1<<i)*shu[i]*(n-shu[i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}
