#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *pa;

  if((pa=fopen("D:\\456.txt","a"))==NULL)
  {printf("file open error!\n");exit(0);}//�ж��Ƿ�򿪳ɹ�
  char ch;
  while((ch=getchar())!='#')
  {
      fputc(ch,pa);
  }

  if(fclose(pa))//�ж��Ƿ�رճɹ�
  {
      printf("error\n");exit(0);
  }




    return 0;
}
