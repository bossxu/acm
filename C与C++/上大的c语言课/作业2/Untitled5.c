
#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a+b<=c||a+c<=b||b+c<=a)
    {
        printf("not triangle");
    }
    else
    {
        if(a*a+b*b==c*c||b*b+c*c==a*a||a*a+c*c==b*b)
        {
            printf("right triangle");
        }
        else
        {
            if(a==b||b==c||a==c)
            {
                if(a==b&&b==c)
                {
                    printf("equilateral triangle");
                }
                else
                {
                    printf("isosceles triangle");
                }

            }
            else
            {
                printf("arbitrary triangle");
            }
        }




    }
    return 0;
}
