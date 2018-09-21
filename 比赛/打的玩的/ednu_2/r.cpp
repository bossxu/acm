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
  int a,b,c,d;
  while(cin>>a>>b>>c>>d)
  {
    a+=b+c;
    if(a>=d)
    {
      cout<<"Pooh out"<<endl;
    }
    else
    {
      cout<<"Stuck in the howse forever"<<endl;
    }
  }
  return 0;
}
