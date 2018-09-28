//langman
#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ld double
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 1e5+5;
// 这个看起来好像就是一道随机的题
// 其中三角形外心。ememem 没有板子，当时没过就有可能是精度问题
// 我那个时候对于每个点我是进行公式计算，计算几何碰少了。
// 不过这套题真的不错，很多的题并不是不能写，只是没有想到。
struct point
{
  ld x,y;
}Q[N];
struct line
{
  point a,b;
};
double distance(point a,point b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point intersection(line u,line v){
    point ret=u.a;
    double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
            /((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x+=(u.b.x-u.a.x)*t;
    ret.y+=(u.b.y-u.a.y)*t;
    return ret;
}
point circumcenter(point a,point b,point c){
    line u,v;
    u.a.x=(a.x+b.x)/2;
    u.a.y=(a.y+b.y)/2;
    u.b.x=u.a.x-a.y+b.y;
    u.b.y=u.a.y+a.x-b.x;
    v.a.x=(a.x+c.x)/2;
    v.a.y=(a.y+c.y)/2;
    v.b.x=v.a.x-a.y+c.y;
    v.b.y=v.a.y+a.x-c.x;
    return intersection(u,v);
}
int n;
bool check(point p,ld r)
{
  int ans = 0;
  for(int i = 0;i<n;i++)
  {
    if(fabs(distance(p,Q[i]) - r) <eps)
    //cout<<distance(p,Q[i])<<endl;
      ans++;
  }
  return ans >= (n+1)/2 ;
}
int main()
{
//  ios_close;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  srand(time(NULL));
  int t;scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
      scanf("%lf%lf",&Q[i].x,&Q[i].y);
    }
    if(n == 1 || n == 2)
    {
      printf("%lf %lf 1\n",Q[0].x+1,Q[0].y);
      continue;
    }
    if(n == 3 || n == 4) //这个没有想到，比赛的时候
    {
      point a;
      a.x = (Q[0].x+Q[1].x)/2;
      a.y = (Q[0].y+Q[1].y)/2;
      printf("%lf %lf %lf\n",a.x,a.y,distance(a,Q[0]));
      continue;
    }
    //cout<<"hello"<<endl;
    point ans;
    ld r;
    while(true)
    {
      int r1,r2,r3;
      r1 = rand()%n;
      r2 = rand()%n;while(r2 == r1) r2 = rand()%n;
      r3 = rand()%n;while(r2 == r3 || r3 == r1) r3 = rand()%n;
      // 无重点 ，判共线; 向量法
      //cout<<r1<<" "<<r2<<" "<<r3<<endl;
      point p1,p2;
      p1.y = Q[r2].y-Q[r1].y;p1.x = Q[r2].x-Q[r1].x;
      p2.y = Q[r3].y-Q[r2].y;p2.y = Q[r3].y-Q[r2].y;
      if(fabs(p1.y*p2.x - p2.y*p1.x) < eps) continue;
      ans = circumcenter(Q[r1],Q[r2],Q[r3]);
      r = distance(ans,Q[r1]);
      if(check(ans,r))
      {
        break;
      }
    }
    printf("%lf %lf %lf\n",ans.x,ans.y,r);
  }
  return 0;
}
