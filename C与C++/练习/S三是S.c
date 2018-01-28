#include<stdio.h>
#include<math.h>
int main()
{

    float x;
    scanf("%f",&x);

      double it,item,y,sum=0;
    int i,fu;

    it=1;fu=1;y=x;
    item=1;
    for(i=1;fabs(item)>=1e-6;i++)
    {
        //for(j=1;j<(2*i-1);j++)
        //{
            //y=y*x;
        //}
        item=fu*y/((2*i-1)*it);
        sum=sum+item;
        it=it*i;
        fu=-fu;
        y=x*x*y;
    }
        printf("%lf\n",sum);
        //printf("%lf",it);

    return 0;
}
