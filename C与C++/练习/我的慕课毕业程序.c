#include <stdio.h>
int main()
{
    int score[10]={67,98,75,63,82,79,81,91,66,84};
    int i,j,sum,max,min,temp;float ave;
    sum=0;
    for(i=9;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(score[j]<score[j+1])
            {
              temp=score[j];
              score[j]=score[j+1];
              score[j+1]=temp;
            }
        }
        sum=sum+score[i];
    }
    ave=sum/10.0;
    for(i=0;i<=9;i++)
    {
        printf("%d ",score[i]);
    }
    printf("\n");
    printf("%d %d %d %.2f",sum,score[0],score[9],ave);






    return 0;
}






