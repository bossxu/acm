//感觉栈更多只是个思想，有太多的办法可以简单的解决这玩意。

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Size 20
typedef char Elem;//申明字符型的类型
typedef struct zhan
{
    Elem *top;//这里的ELem的意义在于它存储的数据形式；
    Elem *end;
    int zhansize;
}zhanlie;//zhanlie就相当于一个小对象
void creat(zhanlie *z)//创建一个栈
{
    z->end=(Elem *)malloc(Size*sizeof(Elem));//先给他释放多大的空间
    if(!z->end) exit(0);//看是不是释放空间成功
    z->top=z->end;//刚开始的时候栈顶就是栈底
    z->zhansize=Size;//栈的容量；
}
void push(zhanlie *z,Elem e)//压栈的操作
{
  if((z->top-z->end)==z->zhansize)//如果栈满了，就要给他追加空间
  {
     z->end=(Elem *)realloc(z->end,(z->zhansize+Size));//目的追加空间。引用新的函数relloc
     if(!z->end) exit(0);//目的是看前面的那个函数是否成功了；
     z->top=z->end+z->zhansize;//从新设置栈顶，或者说确定栈顶所在的位置
     z->zhansize=z->zhansize+Size;//从新设置栈的大小，容量；
  }
  *(z->top)=e;
    z->top++;
}
void Out(zhanlie *z,Elem *e)//出栈的操作,利用指针就可以直接对地址进行操作。不用去return了；
{
    if(z->top==z->end)//栈空的意思;
        return 0;
    *e=*(--(z->top));//理解下为什么要减；
}
void Clean(zhanlie *z)//栈的清空
{
    z->top=z->end;
}
void Destory(zhanlie *z)//销毁栈
{
    int i,len;
    len = zhanlen(*z);
    for(i=0;i<len;i++) //底层破坏法
    {
        free(z->end);//释放空间；
        z->end++;
    }
    z->top=z->end=NULL;
    z->zhansize=0;
}
int zhanlen(zhanlie *z)//求的是栈的当前容量
{
    return (z->top-z->end);
}
int main()
{
    /***********************

    **********用来解决二进制与十进制的转换

    *******************************/
   zhanlie z;
   Elem c,a;
   int i,len,shi=0,zhu=0;
   creat(&z);
   printf("请输入你要转换的二进制的数：并以回车结束\n");

   while((c=getchar())!='\n')//把这个看成一个个字符，方便读入。
   {
       push(&z,c);
   }

   printf("\n当前你的栈的实际容量为:%d",zhanlen(&z));
   len=zhanlen(&z);
   for(i=0;i<len;i++)
   {
       Out(&z,&a);
       shi=shi+(int)(a-'0')*pow(2,i);
   }
   printf("\n十进制的表达方式为：%d",shi);




    return 0;
}
