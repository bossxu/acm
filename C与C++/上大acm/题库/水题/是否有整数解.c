#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,n,t;
    int a,b,c;
    scanf("%d",&n);getchar();
    while(n--)
{
    scanf("%d%d%d",&a,&b,&c) ;
    if(a<b)
    {
        t=a;a=b;b=t;
    }
    for(i=b;i>0;i--)
    {
        if(a%i==0&&b%i==0) break;
    }
    if(c%i==0) printf("Yes");
    else printf("No");
}
    return 0;
}
