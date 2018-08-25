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
  int t;
  scanf("%d",&t);
  while(t--)
  {
    ll n,a;
    scanf("%lld%lld",&n,&a);
    if(n == 0 || n>2)
    {
      printf("-1 -1\n");
    }
    if(n == 1)
    {
      printf("1 %lld\n",a+1);
    }
    if(n == 2)
    {
      if(a == 1 || a == 2)
      {
        printf("-1 -1\n");
        continue;
      }
      if(a%2)
      {
        ll tot = a*a;
        printf("%lld %lld\n",tot/2,tot-tot/2);
        //cout<<tot/2<<" "<<tot-tot/2<<endl;
      }
      else
      {
        ll tot = a*a/2;
        printf("%lld %lld\n",tot/2-1,tot/2+1);
        //cout<<tot/2-1<<" "<<tot/2+1<<endl;
      }
    }
  }
  return 0;
}
