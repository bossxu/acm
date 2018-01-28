#include<stdio.h>
int main()
{
   char a,b;
   scanf("%c%c",&a,&b);
   int c,d;
   c=a;
   d=b;
   c=c+32;
   d=d+32;
   a=c;
   b=d;
   printf("Use putchar:");
   putchar(a);putchar(' ');putchar(b);putchar('\n');
   printf("Use printf:%c %c",c,d);



    return 0;

}
