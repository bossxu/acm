#include<stdio.h>
int main()
{
    int n ,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            putchar(' ');
        }
        for(j=1;j<=(2*i-1);j++)
        {
            putchar('*');
        }

       printf("\n");

    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<=i;j++)
        {
            putchar(' ');
        }
        for(j=1;j<=2*(n-i)-1;j++)
        {
            putchar('*');
        }
        putchar('\n');

    }



    return 0;
}
