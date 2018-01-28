#include<stdio.h>

int main()
{
    int num[5];
    void sca(int *p);
    void pai(int *p);
    void pri(int *p);
    sca(num);
    pai(num);
    pri(num);

    return 0;
}
void sca(int *p)
{
    int i=0;
    for(;i<5;i++)
    {
        scanf("%d",p+i);
    }
}
void pai(int *p)
{
    int i,j,t;
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(*(p+i)<*(p+j))
            {
                t=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=t;

            }
        }
    }
}
void pri(int *p)
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%d ",*(p+i));
    }
}
