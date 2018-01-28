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
const int maxn=505;
// 知识点分解：凸包问题
struct Point  
{  
    int x,y,k,id,vis,flag;  
    Point(int x=0,int y=0):x(x),y(y) {} //构造函数  
};  
typedef Point Vector;  
Point operator-(Point A,Point B)  
{  
    return Point(A.x-B.x,A.y-B.y);  
}  
int Cross(Point A,Point B)  //向量积
{  
    return A.x*B.y-A.y*B.x;  
}  
int cmp1(Point a,Point b)  
{  
    if(a.k==b.k)  
    {  
        if(a.x==b.x)return a.y<b.y;  
        return a.x<b.x;  
    }  
  
    return a.k>b.k;  
}  
int cmp2(Point a,Point b)  
{  
    return a.id<b.id;  
}  
  
int ConvexHull(Point* p,int n,Point* ch)//求凸包  
{  
    int m=0;  
    for(int i=0;i<n;i++)  
    {  
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;  
        ch[m++]=p[i];  
    }  
    int k=m;  
    for(int i=n-2;i>=0;i--)  
    {  
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;  
        ch[m++]=p[i];  
    }  
    if(n>1)m--;  
    return m;  
} 
int main()
{
    int n,co=0;
    while(cin>>n && n)
    {
        Point node1[maxn];//存数据的
        Point node2[maxn];//跑凸包的
        Point node3[maxn];//凸包上的点
        int m=0;
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            node1[i].x=a,node1[i].y=b,node1[i].k=c;
            node1[i].flag=node1[i].vis=0;
            node1[i].id = i;
            m=max(m,c);
        }
        sort(node1+1,node1+1+n,cmp1);
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(node1[i].k==m)
            {
                node2[c++]=node1[i];
            }
        }
        int l = ConvexHull(node2,c,node3);
        for(int i=0;i<c;i++)  
        {  
            for(int j=0;j<l;j++)  
            {  
                if(Cross(node3[j]-node3[(j+1)%m],node3[j]-node2[i])==0)  
                {  
                    if(!node1[i].vis)//该点没有与之重合且速度相同的点  
                    node1[i].flag=1;  
                    break;  
                }  
            }  
        }  
        sort(node1+1,node1+n+1,cmp2);
        printf("Case #%d: ",++co);  
        for(int i=0;i<n;i++)printf("%d",node1[i].flag);  
        printf("\n");           


    }
    
    return 0;
}