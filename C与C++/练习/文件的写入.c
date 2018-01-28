#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *pa;

  if((pa=fopen("D:\\456.txt","a"))==NULL)
  {printf("file open error!\n");exit(0);}//判断是否打开成功
  char ch;
  while((ch=getchar())!='#')
  {
      fputc(ch,pa);
  }

  if(fclose(pa))//判断是否关闭成功
  {
      printf("error\n");exit(0);
  }




    return 0;
}
