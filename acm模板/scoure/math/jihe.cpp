const double eps=1e-8;//解析几何中有时并不能保证等于0，在误差范围就行
struct CPoint//点的存法
{
    double x,y;
}point[103];
int dcmp(double x)//不晓得干啥
{
    if(x<-eps) return -1;
    else   return (x>eps);
}
double cross(CPoint p0,CPoint p1,CPoint p2)//点乘
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double dot(CPoint p0,CPoint p1,CPoint p2)//叉乘
{
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
int PointOnSegment(CPoint p0,CPoint p1,CPoint p2)//判断点是否在线段上
{
    return dcmp(cross(p0,p1,p2))==0&&dcmp(dot(p0,p1,p2))<=0;
}
int PointInPolygon(CPoint cp,CPoint p[],int n)//判断点是否在多边形中
{
    int i,k,d1,d2,wn=0;
  //  double sum=0;
    p[n]=p[0];
    for( i=0;i<n;i++)
    {
        if(PointOnSegment(cp,p[i],p[i+1])) return 2;
        k=dcmp(cross(p[i],p[i+1],cp));
        d1=dcmp(p[i+0].y-cp.y);
        d2=dcmp(p[i+1].y-cp.y);
        if(k>0&&d1<=0&&d2>0)wn++;
        if(k<0&&d2<=0&&d1>0)wn--;
    }
    return wn!=0;
}
