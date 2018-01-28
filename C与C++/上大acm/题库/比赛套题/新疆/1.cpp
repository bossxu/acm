
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
using namespace std;
#define eps 1e-6
struct point
{
    double x,y;
}Point[10];
struct line
{
    point a,b;
}Line[10];
double dis(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
point intersction(line u,line v)
{
    point ret=u.a;
    double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x+=(u.b.x-u.a.x)*t;
    ret.y+=(u.b.y-u.a.y)*t;
    return ret;
}
point center(point a,point b,point c)
{
    line u,v;
    u.a.x=(a.x+b.x)/2;
    u.a.y=(a.y+b.y)/2;
    u.b.x=u.a.x-a.y+b.y;
    u.b.y=u.a.y+a.x-b.x;
    v.a.x=(a.x+c.x)/2;
    v.a.y=(a.y+c.y)/2;
    v.b.x=v.a.x-a.y+c.y;
    v.b.y=v.a.y+a.x-c.x;
    return intersction(u,v);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double x1,x2,x3,y1,y2,y3;
        double x,y;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x,&y);
        point a,b,c,d,o;
        a.x=x1,a.y=y1;
        b.x=x2,b.y=y2;
        c.x=x3,c.y=y3;
        d.x=x,d.y=y;
        o=center(a,b,c);
        if(dis(o,a)<dis(o,d))
        {
            printf("Accepted\n");
        }
        else
            printf("Rejected\n");
    }
}
