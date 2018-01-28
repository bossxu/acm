#include<stdio.h>
int main()
{
    int n,item,i,chen;
    scanf("%d",&n);
    item=1;chen=0;
    for(i=1;i<=n;i++)
    {
        item=item*i;
        chen=item+chen;
    }
    printf("%d",chen);
    return 0;
}
