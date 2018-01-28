#include<stdio.h>
int main()
{
    int n,ju[6][6],i,j,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&ju[i][j]);
            if(i>j)
            {
                if(ju[i][j]!=0)
                    k=1;
            }
        }
    }
    if(k==0)
        printf("YES");
    else
        printf("NO");


    return 0;
}
