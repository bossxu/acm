#include<stdio.h>
int main()
{
    int i,j,k,n,ju[6][6],pan[6],sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&ju[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
            {
                if(ju[i][j]>=ju[i][k]&&ju[i][j]<=ju[k][j])
                    pan[k]=0;
                else
                    pan[k]=1;
            }
            for(k=0;k<n;k++)
            {
                sum=sum+pan[k];
            }
            if(sum==0)
            {
                printf("%d %d",i,j);break;
            }
        }
        if(sum==0) break;
    }

    if(sum!=0) printf("NO");
    return 0;
}
