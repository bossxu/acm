#include<stdio.h>
int main()
{
    int num[11];
    int i,k;
    for(i=0;i<10;i++)
    {
        scanf("%d",&num[i]);
    }
    putchar('\n');
    scanf("%d",&num[i]);
    k=num[i];
    for(i=9;i>=0;i--)
    {
        if(k>num[i])
        {
            num[i+1]=num[i];
            num[i]=k;
        }
        else
       {
         break;
       }

    }
    for(i=0;i<11;i++)
    {
        printf("%d ",num[i]);
    }


    return  0;
}
