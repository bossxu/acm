#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *pa;
  int m,n;//ntf("请输入两个数");
  //;scanf("%d%d",&m,&n);
  if((pa=fopen("D:\\123.txt","r"))==NULL)
  {printf("file open error!\n");exit(0);}//判断是否打开成功
  char zi1[]="m=",zi2[]="n=",ch;
  /*fwrite(zi1,1,2,pa);fwrite(&m,1,4,pa);
  fwrite(zi2,1,2,pa);fwrite(&n,1,4,pa);*/
  while((ch=fgetc(pa))!=EOF)
  {
      putchar(ch);
      //ch=fgetc(pa);
  }
  if(fclose(pa))//判断是否关闭成功
  {
      printf("error\n");exit(0);
  }




    return 0;
}
