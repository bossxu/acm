#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int i,j;
    int a[100005];
    int n,m;
    int b,c;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        while(m--)
        {
            scanf("%d%d",&b,&c);
            if(a[b]==a[c] ) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
