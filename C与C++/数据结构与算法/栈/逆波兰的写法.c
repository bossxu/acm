#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 20
#define SIZEADD 10

 typedef float Elem;

typedef struct zhan//��������
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
void Push(Lie *z,Elem a)//��ջ
{
    if((z->top-z->base)==z->size)
    {
     z->base=(Elem *)realloc(z->base,(z->size+SIZEADD));//Ŀ��׷�ӿռ䡣�����µĺ���relloc
     if(!z->base) exit(0);//Ŀ���ǿ�ǰ����Ǹ������Ƿ�ɹ��ˣ�
     z->top=z->base+z->size;//��������ջ��������˵ȷ��ջ�����ڵ�λ��
     z->size=z->size+SIZEADD;//��������ջ�Ĵ�С��������
    }
    *(z->top)=a;
    z->top++;
}
void Pop(Lie *z,Elem *a)//��ջ
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

  printf("�밴���沨����˳�������룬���Կո����,�ԡ�#������:\n");
  scanf("%c",&c);

  while(c != '#')
  {
    while(isdigit(c)||c=='.')//�������֣��Լ���װ����,���������Ŀ����ȷ���Ƿ�������
    {
        str[i++]=c; str[i]='\0';
        if(i>=10)  printf("\n����������ݹ���\n");
        scanf("%c",&c);
        if(c==' ')
        {
            d=atof(str);//��������������ǰ�������װ�����ַ�����ɸ�����
            Push(&z,d);
            i=0;
            break;
        }
    }

      switch(c)// Ϊ����ʱ�����еĲ�����
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
          printf("\n���յĽ��Ϊ:%f",d);




    return 0;
}
