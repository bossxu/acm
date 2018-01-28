#include<stdio.h>
#include<string.h>
int main()
{
    char a[240];
    int i,j,n,con;
    scanf("%d",&n);
    while(n--)
    {
        i=0;
       gets(a);getchar();
        scanf("%d",&con);
        while( con--)
        {
            for(j=0;j!=strlen(a)-1 && a[j]<a[j+1]  ||  a[j]=='k';j++);
            a[j]='k';
        }
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='k') continue;
            else printf("%c",a[i]);
        }
    }

    return 0;
}
