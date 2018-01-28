#include<stdio.h>

void print()//有点骚
{
    char a;
    scanf("%c",&a);
    if(a!='#') print();
    if(a!='#') printf("%c",a);
}
int main()
{
    printf("请输入字符串：并以#结束\n");
    print();
    return 0;
}
