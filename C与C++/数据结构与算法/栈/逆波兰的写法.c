#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 20
#define SIZEADD 10

 typedef float Elem;

typedef struct zhan//申明类型
{
    Elem *top;
    Elem *base;
    int size;
}Lie;
void creat(Lie *z)
{
    z->base=(Elem *)malloc(SIZE*sizeof(Elem));   if(!z->base) exit(0);
    z->top=z->base;
    z->size=SIZE;
}
void Push(Lie *z,Elem a)//进栈
{
    if((z->top-z->base)==z->size)
    {
     z->base=(Elem *)realloc(z->base,(z->size+SIZEADD));//目的追加空间。引用新的函数relloc
     if(!z->base) exit(0);//目的是看前面的那个函数是否成功了；
     z->top=z->base+z->size;//从新设置栈顶，或者说确定栈顶所在的位置
     z->size=z->size+SIZEADD;//从新设置栈的大小，容量；
    }
    *(z->top)=a;
    z->top++;
}
void Pop(Lie *z,Elem *a)//出栈
{
    if(z->top==z->base)
        return ;
    *a=*(--(z->top));
}
int main()
{
  Lie z;
  float a,e,d;
  char c;
  int i=0,j,k;
  char str[SIZE];

  creat(&z);

  printf("请按照逆波兰的顺序来输入，并以空格隔开,以‘#’结束:\n");
  scanf("%c",&c);

  while(c != '#')
  {
    while(isdigit(c)||c=='.')//过虑数字，以及组装数字,这个函数的目的是确定是否是数字
    {
        str[i++]=c; str[i]='\0';
        if(i>=10)  printf("\n你输入的数据过大\n");
        scanf("%c",&c);
        if(c==' ')
        {
            d=atof(str);//这个函数的作用是把数字组装；把字符串变成浮点数
            Push(&z,d);
            i=0;
            break;
        }
    }

      switch(c)// 为符号时，进行的操作。
      {
          case '+':Pop(&z,&a);Pop(&z,&e);Push(&z,a+e);break;
          case '-': Pop(&z,&a); Pop(&z,&e);Push(&z,e-a);break;
          case '*':Pop(&z,&a);Pop(&z,&e);Push(&z,a*e);break;
          case '/':
              Pop(&z,&a);
              Pop(&z,&e);
              if(a!=0)
              Push(&z,e/a);
              else
              printf("\nerror\n");
                break;
      }
      scanf("%c",&c);
  }

          Pop(&z,&d);
          printf("\n最终的结果为:%f",d);




    return 0;
}
