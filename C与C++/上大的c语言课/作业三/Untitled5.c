#include<stdio.h>
int main()
{

    float x;
    scanf("%f",&x);

      double it,y,sum=0;
    int i,fu,j;

    it=1;fu=1;y=x;
    for(i=1;i<=200;i++)
    {
        //for(j=1;j<(2*i-1);j++)
        //{
            //y=y*x;
        //}

        sum=sum+fu*y/((2*i-1)*it);
        it=it*i;
        fu=-fu;
        y=x*x*y;
    }
        printf("%lf\n",sum);
        //printf("%lf",it);

    return 0;
}
