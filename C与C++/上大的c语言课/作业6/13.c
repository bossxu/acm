#include<stdio.h>
int main()
{
   char zifu[200],z;int i=0;
   printf("Input a string: ");
   /*while((zifu[i]=getchar())!='\n')
   {
       i++;
   }*/
   printf("Input a char: ");scanf("%c",&z);
   printf("After deleted,the string is: ");
   printf("a");


    return 0;
}
void del(char zi[],char z,int n)
{
   int i=0;
   for(;i<n;i++)
   {
       if(zi[i]==z) continue;
       printf("%c",zi[i]);
   }


}
