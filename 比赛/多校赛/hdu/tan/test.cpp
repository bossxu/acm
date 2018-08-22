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

int gcd(int a,int b)
{
  return b == 0?a:gcd(b,a%b);
}
int main()
{
  freopen("out.txt","w",stdout);
  int tot = 0;
  for(int i = 1;i<=100;i++)
  {
    ll ans = 0;
    for(int j = 1;j<i;j++)
    {
      if(gcd(i,j)==1 && gcd(i+j,i-j)!=1)
      {
        cout<<i<<" "<<j<<" | ";
        ans++;
      }
    }
    cout<<endl;
    cout<<i<<" "<<ans;
    cout<<endl;
  }

  return 0;
}
