#include<stdio.h>
int main()
{
    int n,i,j;
    printf("������Ҫ���ɼ��׷���:");scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n;j++) printf("%3d",(j+i)%n);
        putchar('\n');
    }


    return 0;
}
