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
int main()
{
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    n+=2;
    if(n%2==0)
    {
      cout<<n/2*n/2<<endl;
    }
    else
    {
      cout<<(n/2+1)*(n/2)<<endl;
    }

  }
  return 0;
}
