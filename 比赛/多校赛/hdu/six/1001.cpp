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
  //ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    long double a,b;
    cin>>a>>b;
    long double ans = a*pi + 2*b;
    printf("%.6Lf\n",ans-0.0000005);
  }
  return 0;
}
