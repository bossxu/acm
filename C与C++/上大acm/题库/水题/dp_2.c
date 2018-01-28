#include<stdio.h>
#include<math.h>
#include<string,h>

int main()
{
    int n,m;
    int Shu[105][105];
    int i,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(Shu,0,sizeof(Shu));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
               scanf("%d",&Shu[i][j]);
    }

    return 0;
}
