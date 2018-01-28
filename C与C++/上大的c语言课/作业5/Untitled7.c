#include<stdio.h>
int main()
{
    int n,chengji[100],he[100],j=0,i=0,k=0;float avg,sum=0;
    scanf("%d",&n);putchar('\n');
    while(i<n)
    {
        scanf("%d",&chengji[i]);
        sum=sum+chengji[i];
        i++;
    }
    avg=sum/n;
    printf("%.2f\n",avg);
    if(avg!=1)
{
     for(k=0;k<i;k++)
    {
        if(chengji[k]<avg)
        {
            he[j]=chengji[k];
            j++;
        }
    }
    for(k=0;k<j-1;k++)
    {
        printf("%d,",he[k]);
    }
    printf("%d",he[k]);

}


    return 0;
}
