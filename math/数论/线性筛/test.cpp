#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    ll ans = 0;
    for(int i = 1;i<n;i++)
    {
      for(int j = 1;j<n;j++)
      {
        if(i*j%n)
        {
          ans++;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
