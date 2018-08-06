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
  int t;
  cin>>t;
  while(t--)
  {
    int m;
    double R;
    scanf("%d%lf",&m,&R);
    double csl = 2*pi*R;
    double x,y,r;
    for(int i = 1;i<=m;i++)
    {
      scanf("%lf%lf%lf",&x,&y,&r);
      double dis = sqrt(x*x + y*y);
      // if(abs(R-r-dis)<eps)
      // {
      //   csl += 2*pi*r;
      //   continue;
      // }
      if(R-r-dis > eps  || dis-R-r >eps )
        continue;
      double li = acos((R*R + dis*dis - r*r)/(2*R*dis))*2;
      double wai = acos((r*r + dis*dis - R*R)/(2*r*dis))*2;
      csl = csl - li*R + wai*r;
    }
    printf("%.7lf\n",csl);
  }
  return 0;
}
