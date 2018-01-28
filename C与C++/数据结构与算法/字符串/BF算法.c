#include<stdio.h>
#include<string.h>
#define MAX 30
int Pan (char c[],char a[])
{
    int i,j,n;
    for(i=0;i<strlen(a);i++)
    {
        for(j=0;j<strlen(c);j++)
        {
            if(a[i]!=c[j]) break;
            else i++;
        }
        if(j==strlen(c)) return i-j+1;
    }
    printf("对不起，母串中没有子串\n");
    return 0;
}
int main()
{
    char a[MAX],c[MAX];
    printf("请输入你想匹配的母串：\n");
    gets(a);
    printf("请输入你想匹配的子串：\n");
    gets(c);
    printf("位置在%d",Pan(c,a));
    return 0;
}
