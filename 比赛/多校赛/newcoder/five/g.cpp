#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;


int main()
{
  ll c,d;
  while(cin>>c>>d)
  {
    ll op = d/c;
    if(op == 0)
    {
      cout<<-1<<endl;
    }
    else
    {
      if(op == 1)
      {
        cout<<c*c<<endl;
      }
      else
      {
        cout<<op*(op-1)*c*c<<endl;
      }
    }
  }
  return 0;
}
