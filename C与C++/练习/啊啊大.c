#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);int a[20][20];
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++) a[i][j]=i+1;
    }
    for(j=1;j<n;j++)
    {
        for(i=0;i<j;i++) a[i][j]=j+1;
    }
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++) printf("%4d",a[i][j]);
       putchar('\n');
    }



    return 0;
}

