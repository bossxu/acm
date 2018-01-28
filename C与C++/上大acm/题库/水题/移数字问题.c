#include<stdio.h>
int main()
{
    int shu[9];
    int i,j,t;
    shu[0]=0;
    while(scanf("%d",&shu[1])==1)
    {
        for(i=2;i<9;i++) scanf("%d",&shu[i]);
        for(i=2;i<9;i++)
        {
            for(j=1;j<9-i;j++)
            {
                if(shu[j]>shu[j+1])
                {
                    t=shu[i];shu[i]=shu[j];shu[j]=t;
                    printf("%d 0\n%d %d\n0 %d\n",j,j+1,j,j+1);
                }
                else
                    break;
            }
        }
        printf("-1\n");
    }
    return 0;
}
