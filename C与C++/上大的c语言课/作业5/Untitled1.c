#include<stdio.h>
int main()
{
    int ju[4][4];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&ju[i][j]);

        }
        putchar('\n');

    }
    int sum=0;
    for(i=0;i<4;i++)
    {
        sum=sum+ju[i][i];
    }

    printf("%d",sum);
    return 0;
}
