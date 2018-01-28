#include<stdio.h>
int main()
{
    printf("please enter the fenzi,fenmu of two complex:\n");
    int shu[4],i;
    for(i=0;i<4;i++)
    {
        scanf("%d",&shu[i]);
    }
    int a,b,j;
    b=shu[1]*shu[3];
    a=shu[0]*shu[3]+shu[1]*shu[2];
    if(a<b) j=a;
    else j=b;
    for(i=j;i>0;i--)
    {
        if(a%i==0&&b%i==0)
        {
            a=a/i;
            b=b/i;
            break;
        }
    }
    printf("the result is %d/%d",a,b);
    return 0;
}
