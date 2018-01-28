#include<stdio.h>
int main()
{
   int n,a,b,i;
   float c,d;

   c=0;a=0;d=0;b=0;i=0;

       while(i<=100)
   {
       scanf("%d",&n);
       if (n==0) break;
       if (n%2==0)
        {a=a+1;
        c=c+n;}
        else
        {b=b+1;
        d=d+n;}

   }
   if (b==0) d=d;else d=d/b;
   if (a==0) c=c;else c=c/a;


   printf("%d %.2f\n",b,d);
   printf("%d %.2f\n",a,c);


    return 0;
}
