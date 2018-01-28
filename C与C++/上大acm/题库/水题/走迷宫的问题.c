#include<stdio.h>
#include<string.h>
#define max 105

typedef struct  migong{
    int x,y;
} point;

int main()
{
    int Mi[max][max];
    int m,n;
    int i,j;
    while(scanf("%d%d",&m,&n)==2)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&Mi[i][j]);
            }
        }




    }


    return 0;
}
