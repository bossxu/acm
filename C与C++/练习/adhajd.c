#include<stdio.h>
void rever(int *pa,int*pb);
int main()
{
    int shu[5];
    int i=0;
    for(;i<5;i++)
    {
        sacnf("%d",&shu[i]);
    }
    int *pa,*pb;
    pa=shu;
    pb=shu+5;
    rever(pa,pb);


    return 0;
}
void rever(int *pa,int*pb)
{
    int t;
    for(;pa<pb;pa++,pb--)
    {
        t=*pa;
        *pa=*pb;
        *pb=t;
    }


}
