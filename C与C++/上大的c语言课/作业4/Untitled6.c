#include<math.h>
#include<stdio.h>
float daan(float a)
{
    float sum;
    int i;
    sum=1+a;
    for(i=1;i<10;i++)
    {
        sum=sum*(1+a);
    }
    return sum;

}
int main()
{
    float x1=0.1,x2=0.2,mid;
    while(fabs(x1-x2)>1e-5)
    {
        mid=(x1+x2)/2;
        if(daan(mid)>4)
        {
            x2=mid;
        }
        else
        {
            x1=mid;
        }


    }
   printf("%2.1f",100*mid);putchar('%');

    return 0;
}
