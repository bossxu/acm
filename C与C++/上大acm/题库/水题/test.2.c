#include<stdio.h>
#include<math.h>
#define z 1e-6

int main()
{
    int n,i=0;
    float a,jie,sun;
    while(scanf("%d",&n)==1)
    {
      a=1;jie=1;sun=0;i=0;
     while(jie>z)
     {
         sun+=jie;
         jie=jie*n/(++i);
        }
        printf("e 的 %d 次方 的值为 %.5f\n",n,sun);
    }
    return 0;
}
