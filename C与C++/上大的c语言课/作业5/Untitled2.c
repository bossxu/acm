#include<stdio.h>
int main()
{
    int i,j;
    int ju[5][5];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i==j||i+j==4)
                ju[i][j]=1;
                else
                ju[i][j]=0;
        }
    }
  for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d ",ju[i][j]);
        }
        printf("\n");
    }
    return 0;
}
