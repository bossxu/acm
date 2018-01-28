#include<stdio.h>
int main()
{
    char zifu[80];
    int i=0;
    while((zifu[i]=getchar())!='\n')
    {
        i++;
    }
    int j=i-1;i=0;
    while(j>i)
    {
        if(zifu[j]!=zifu[i])
        {
            printf("NO");break;
        }
        j--;
        i++;
    }
    if(j<=i) printf("YES");
    return 0;
}
