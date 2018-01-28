#include<stdio.h>
int main()
{
    int n=6,i,j,item=0;
   while(n<=100)
   {
       for(i=2;i<n;i++)
       {
           j=n-i;
           if(prime(i)*prime(j)!=0)
           {
               printf("%4d=%2d+%2d",n,i,j);item++;
               break;
           }
       }
       n+=2;
       if(item%5==0) putchar('\n');
   }



    return 0;
}
int prime(int i)
{
    int j;
    for(j=2;j<i;j++)
    {
        if(i%j==0) break;
    }
    if(i==j) return 1;
    else return 0;
}
