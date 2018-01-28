#include<stdio.h>
int main()
{
    int shu[5];
    int i=0;
    for(;i<5;i++)
    {
        scanf("%d",&shu[i]);
    }
    int *pa,*pb;
    pa=shu;
    pb=shu+4;
    int t;
    for(;pa<pb;pa++,pb--)
    {
        t=*pa;
        *pa=*pb;
        *pb=t;
    }
    pa=shu;
    for(i=0;i<5;i++)
    {
        printf("%d",*(pa+i));
    }

return 0;
}
