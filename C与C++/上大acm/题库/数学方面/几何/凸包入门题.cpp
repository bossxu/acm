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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
const int maxn = 210;
// 知识点分解：hdu 1392 凸包
struct point{
    double x,y;
    point (double x=0,double y=0):x(x),y(y){} 
    friend point operator + (point a,point b) {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (point a,point b) {
        return point(a.x-b.x,a.y-b.y);
    }  //构造函数
}p[maxn],res[maxn];
double dis(point a, point b)//两点的距离
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double dot(point a,point b)//叉积
{
   return a.x*b.y-a.y*b.x;
}
bool cmp(point a,point b)  //排序用的
{  
    if(a.y==b.y)  
        return a.x<b.x;  
    else  
        return a.y<b.y;  
}  
int Graham(point* p,int n,point* res) {//算法核心 其中 p是 原始点 res 是我凸上的点 这个函数返回的的是，凸包上有几个点。
    sort(p+1,p+n+1,cmp);
    res[1] = p[1];
    res[2] = p[2];
    int top = 2,len;
    for(int i=3;i<=n;i++) {
        while(top>=2 && dot(p[i] - res[top-1],res[top] - res[top-1])>=0) top--;
        res[++top] = p[i];
    }
    len = top;
    for(int i=n;i>=1;i--) {
        while(top!=len&&dot(p[i]-res[top-1],res[top]-res[top-1])>=0) top--;
        res[++top] = p[i];
    }
    return top;
}
int main(
)
{
    int n;
    while(cin>>n && n)
    {
        for(int i=1;i<=n;i++ )
        {
            cin>>p[i].x>>p[i].y;
        }
        if(n==1) {printf("0.00\n");continue;}
        if(n==2) {printf("%.2lf\n",dis(p[1],p[2]));continue;}
        int m=Graham(p,n,res);
        double total=0;
        for(int i=2;i<=m;i++)
        {
            total += dis(res[i-1],res[i]);
        }
        printf("%.2lf\n",total);

    }
    return 0;
}