#include<stdio.h>

int mai( int n,int m)
{
         if(n==0||m==1) return 1;
    else
        if(n>=m) return mai(n-m,m)+mai(n,m-1);
    else
        if(n<m) return mai(n,n);
}
int main()
{
    int a,b;
   while( scanf("%d",&a)==1)
   {
      printf("%d\n",mai(a,a));
   }

    return 0;
}
