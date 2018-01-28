#include<stdio.h>
int main()
{
    int i,count=0;
    int chou[50005];
    int a,b,c,d,t;
    while(1)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&t);
        count=0;
        for(i=1;i<=t;i++)
        {
            chou[i]=0;
        }
        for(i=a;i<=t;i+=a) chou[i]++;
        for(i=b;i<=t;i+=b) chou[i]++;
        for(i=c;i<=t;i+=c) chou[i]++;
        for(i=d;i<=t;i+=d) chou[i]++;
        for(i=1;i<=t;i++) if(chou[i]>1) count++;
        printf("%d\n",count);
    }
    return 0;
}
