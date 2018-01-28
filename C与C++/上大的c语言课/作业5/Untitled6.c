
#include<stdio.h>
int main()
{
    char num[100];
    unsigned n;int i=0,k=0;
    unsigned j=0;
    scanf("%d",&n);
    while(n!=0)
    {
       num[i]=n%2;
       n=n/2;
       i++;
    }
    for(k=i-1;k>=0;k--)
    {
       j=j*10+num[k];
    }


printf("%d",j);



    return 0;
}
