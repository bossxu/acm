#include <stdio.h>
struct s
{
    int x;
    double y;
}a[300],b;
int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        
        double t;
        int i,j,z;
        for(i=0;i<m;i++)
            a[i].y=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%lf",&t);
                a[j].x=j+1;
                a[j].y=a[j].y+t;
            }
        }
        for(i=0;i<m-1;i++)          //认可度排序
            for(j=0;j<m-i-1;j++)
                if(a[j].y<a[j+1].y)
                {
                    b=a[j];
                    a[j]=a[j+1];
                    a[j+1]=b;
                } 
        for(i=0;i<k-1;i++)          //编号排序
            for(j=0;j<k-i-1;j++)
                if(a[j].x<a[j+1].x)
                {
                    b=a[j];
                    a[j]=a[j+1];
                    a[j+1]=b;
                }

        for(i=0;i<k-1;i++)
            printf("%d ",a[i].x);
        printf("%d\n",a[i].x);
    }
    return 0;
}