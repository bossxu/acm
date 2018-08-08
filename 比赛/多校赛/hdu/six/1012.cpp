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
double g = 9.8;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    double a,b,x,y;
    cin>>a>>b>>x>>y;
    x = -x;
    double si = b/sqrt(a*a+b*b);
    double co = a/sqrt(a*a+b*b);
    int num = 1;
    double vx,vy;
    double v = sqrt(2*g*(y-b*x/a));
    vx = si*v;
    vy = co*v;
    double ax,ay;
    ax = g*si;
    ay = g*co;
    while(x>0)
    {
      double t = 2*vy/ay;
      x -= (vx*t + ax*t*t/2)*co;
      if(x>0) num++;
      vx += ax*t;
    }
    cout<<num<<endl;
  }
  return 0;
}
