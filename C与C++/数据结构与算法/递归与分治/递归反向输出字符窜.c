#include<stdio.h>

void print()//�е�ɧ
{
    char a;
    scanf("%c",&a);
    if(a!='#') print();
    if(a!='#') printf("%c",a);
}
int main()
{
    printf("�������ַ���������#����\n");
    print();
    return 0;
}
