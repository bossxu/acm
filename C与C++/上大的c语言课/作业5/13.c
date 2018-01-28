# include<stdio.h>
int main()
{
    float jiangyu[12],sum=0;
    int bili[12];
    int i=0,k=0;
    for(;i<12;i++)
    {
        scanf("%f",&jiangyu[i]);
    }
    for(i=0;i<12;i++)
    {
        sum=sum+jiangyu[i];
    }

    for(i=0;i<12;i++)
    {
        bili[i]=jiangyu[i]/sum*100;
        int j=jiangyu[i]/sum*1000;
        if(j%10>=5)
            bili[i]++;
    }
    for(i=0;i<12;i++)
    {

        printf("%d(%d%)",i+1,bili[i]);
        for(k=0;k<bili[i];k++)
        {
            putchar('#');
        }
        putchar('\n');
    }


    return 0;
}
