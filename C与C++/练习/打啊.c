#include<stdio.h>
#include<string.h>
int main()
{
    char zifu[50];int i;
    gets(zifu);
    strrev(zifu);
    for(i=0;i<strlen(zifu);i++) printf("%d:%s\n",i+1,zifu+i);
}
