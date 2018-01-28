#include<stdio.h>
int main()
{
    int i,n,n1,n2,n3;
    n1=1;n2=2;
    scanf("%d",&n);
    for(i=3;i<=n;i++)
    {
        n3=n2+n1;
        n1=n2;
        n2=n3;
    }
        printf("%d",n3);

    return 0;
}
