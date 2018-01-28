#include<stdio.h>
#include<string.h>
int main()
{
    printf("请输入要判断的字符串：\n提示：数字也可以是字符组，还有长度不要超过20\n");
    char zifu[20];
    int min,max;
    gets(zifu);
   for(min=0,max=strlen(zifu)-1;min<max;min++,max--)
   {
       if(zifu[min]!=zifu[max]) {printf("这个字符不是回文的");break;}
   }
      if(min>=max) printf("这个字符串是回文的");
}
