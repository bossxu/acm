#include<stdio.h>
#include<string.h>
int main()
{
    printf("������Ҫ�жϵ��ַ�����\n��ʾ������Ҳ�������ַ��飬���г��Ȳ�Ҫ����20\n");
    char zifu[20];
    int min,max;
    gets(zifu);
   for(min=0,max=strlen(zifu)-1;min<max;min++,max--)
   {
       if(zifu[min]!=zifu[max]) {printf("����ַ����ǻ��ĵ�");break;}
   }
      if(min>=max) printf("����ַ����ǻ��ĵ�");
}
