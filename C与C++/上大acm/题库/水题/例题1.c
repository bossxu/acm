#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
 float a,max;
 int n;int count=0;
 {
     while(scanf("%d",&n)==1)
     {
         max=0;
         while(n--)
         {
             scanf("%f",&a);
             if(a>max) max=a;
         }
         printf("Case %d: %.1f\n",++count,max);
     }
 }
return 0;
}
