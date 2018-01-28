#include<stdio.h>

int main()
{
    char num[100];
    unsigned n;int i=0,j,k=0;
    scanf("%d",&n);
    if(n==0) putchar('0');
    else {
            while(n!=0)
    {
       num[i]=n%2;
       n=n/2;
       i++;
    }
    for(j=i-1;j>=0;j--)
    {
        printf("%c",num[j]+'0');
    }
    }






    return 0;
}
