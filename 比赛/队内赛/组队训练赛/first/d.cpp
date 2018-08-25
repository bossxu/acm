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
struct Point
{
  double x,y;
  Point(double x = 0,double y = 0):x(x),y(y){}
}shu[50005];
typedef Point Vector;
struct Line
{
  Point P;
  Vector V;
  double ang;
  Line(){}
  Line(Point P,Vector v):P(P),V(v){ang = atan2(v.y,v.x);}
  bool operator < (const Line& L) const
    {
      return ang<L.ang;
    }
};
double Cross(Vector A, Vector B)
{
  return A.x*B.y-A.y*B.x;
}
Vector operator-(Point A,Point B)
{
  return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Point A,double a)
{
  return Vector(A.x*a,A.y*a);
}
Vector operator+(Point A,Point B)
{
  return Vector(A.x+B.x,A.y+B.y);
}
bool OnLeft(Line L,Point p)
{
  return Cross(L.V,p-L.P)>0;
}
Point GetIntersection(Line a,Line b)
{
  Vector u = a.P-b.P;
  double t = Cross(b.V,u)/Cross(a.V,b.V);
  return a.P + a.V*t;
}
Point p[50005];
Line q[50005];
int HalfplaneIntersection(Line *L,int n,Point* poly)
{
  sort(L,L+n);
  int first,last;
  q[first=last=0] = L[0];
  for(int i = 0;i<n;i++)
  {
    while(first < last && !OnLeft(L[i],p[last-1])) last--;
    while(first < last && !OnLeft(L[i],p[first])) first++;
    q[++last] = L[i];
    if(fabs(Cross(q[last].V,q[last-1].V))<eps)
    {
      last--;
      if(OnLeft(q[last],L[i].P)) q[last] = L[i];
    }
    if(first < last) p[last-1] = GetIntersection(q[last-1],q[last]);
  }
  while(first < last && !OnLeft(q[first],p[last-1])) last--;
  if(last - first <= 1) return 0;
  p[last] = GetIntersection(q[last],q[first]);
  int m = 0;
  for(int i = first;i<=last;i++) poly[m++] = p[i];
  return m;
}
Line L[50005];
Point poly[50005];
int n;
bool check(int st)
{
  st+=1;
  for(int i = 0;i<n;i++)
  {
    L[i] = Line(shu[i],shu[i]-shu[(i+st)%n]);
  }
  int m = HalfplaneIntersection(L,n,poly);
  if(!m) return true;
  return false;
}
int main()
{
  ios_close;
  while(cin>>n && n)
  {
    int left = 0,right = n;
    for(int i = 0;i<n;i++)
    {
      cin>>shu[i].x>>shu[i].y;
    }
    int ans = 0;
    while(left<=right)
    {
      int mid =(left+right)/2;
      if(check(mid))
      {
        ans = mid;
        //left = mid+1;
        right=mid-1;
      }
      else
      {
        left=mid+1;
        //right = mid-1;
      }
    }
    cout << ans <<endl;
  }
  return 0;
}
