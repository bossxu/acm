#include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("* ");
    }
    putchar('\n');
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<=i;j++)
        {
            putchar(' ');
        }
        putchar('*');
        for(j=1;j<=2*(n-i-1)-1;j++)
        {
            putchar(' ');
        }
        putchar('*');putchar('\n');
    }
    for(i=1;i<n;i++)
    {
        putchar(' ');
    }


    putchar('*');

    return 0;
}
