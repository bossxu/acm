#include<stdio.h>
int main()
{
   char a;
   scanf("%c",&a);
   int c;
   c=a;
   if(c<=90&&c>=65)
   {
       c=c+32;
   }
   else if(c<=122&&c>=97)
   {
       c=c-32;
   }
   else
   {
       c=c;
   }
printf("%c",c);

    return 0;

}
