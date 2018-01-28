#include<stdio.h>
int main()
{
   int num[3][3]={
   {68,55,28},
   {36,45,17},
   {77,16,24}};
   int i,j,n;
   scanf("%d",&n);
   for(i=0;i<3;i++)
   {
       for(j=0;j<3;j++)
       {
           if(num[i][j]==n)
           {
               printf("[%d,%d]",i+1,j+1);
                break;
            }
       }
       if(num[i][j]==n&&j!=3) break;
   }
    //printf("%d%d%d",i,j,num[i][j]);

    if(num[i][j]!=n||i>=3||j>=3) printf("[N]");

    return 0;
}
