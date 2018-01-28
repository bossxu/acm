
#include<stdio.h>
int main()
{
    float r;
    double area;
    #define c 3.14159
    printf("Input radius:");
    scanf("%f",&r);
    area= c*r*r;
    printf("radius=%.6f area=%.6f",r,area);


    return 0;
}
