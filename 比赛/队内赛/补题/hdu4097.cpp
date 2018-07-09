#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-8;
//圆反演的题,
//圆的反演是一种把问题转化成相似的一种解法
//很好的一道题,我的数学还有待提高,太菜了
//几何方面的一些题我需要有方面的了解.
//求最小的值也就是这样的操作,装化成三角形的模型
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    double r;
    double x1,x2,y1,y2;
    scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2);
    if(x1 == 0 && y1 == 0)
    {
      printf("%.7lf\n",2*r);
      continue;
    }
    double bi = r * r /(x1*x1 + y1*y1);
    double x3,y3,x4,y4;
    x3 = x1*bi , x4 = x2*bi;
    y3 = y1*bi , y4 = y2*bi;
    double x = (x3+x4)/2;
    double y = (y3+y4)/2;
    double d = sqrt(x*x + y*y);
    //cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
    if(d <= r)
    {
      printf("%.7lf\n",sqrt(pow(x3-x4,2)+pow(y3-y4,2)) / sqrt(bi));
    }
    else
    {
      double kk = r / sqrt(x*x + y*y);
      x = x  * kk, y = y * kk;
      double ans = 2* sqrt(pow(x-x1,2)+ pow(y - y1,2));
      printf("%.7lf\n",ans);
    }
  }
  return 0;
}
