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
    printf("�Բ���ĸ����û���Ӵ�\n");
    return 0;
}
int main()
{
    char a[MAX],c[MAX];
    printf("����������ƥ���ĸ����\n");
    gets(a);
    printf("����������ƥ����Ӵ���\n");
    gets(c);
    printf("λ����%d",Pan(c,a));
    return 0;
}
