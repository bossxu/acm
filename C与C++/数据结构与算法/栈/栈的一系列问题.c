//�о�ջ����ֻ�Ǹ�˼�룬��̫��İ취���Լ򵥵Ľ�������⡣

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Size 20
typedef char Elem;//�����ַ��͵�����
typedef struct zhan
{
    Elem *top;//�����ELem�������������洢��������ʽ��
    Elem *end;
    int zhansize;
}zhanlie;//zhanlie���൱��һ��С����
void creat(zhanlie *z)//����һ��ջ
{
    z->end=(Elem *)malloc(Size*sizeof(Elem));//�ȸ����ͷŶ��Ŀռ�
    if(!z->end) exit(0);//���ǲ����ͷſռ�ɹ�
    z->top=z->end;//�տ�ʼ��ʱ��ջ������ջ��
    z->zhansize=Size;//ջ��������
}
void push(zhanlie *z,Elem e)//ѹջ�Ĳ���
{
  if((z->top-z->end)==z->zhansize)//���ջ���ˣ���Ҫ����׷�ӿռ�
  {
     z->end=(Elem *)realloc(z->end,(z->zhansize+Size));//Ŀ��׷�ӿռ䡣�����µĺ���relloc
     if(!z->end) exit(0);//Ŀ���ǿ�ǰ����Ǹ������Ƿ�ɹ��ˣ�
     z->top=z->end+z->zhansize;//��������ջ��������˵ȷ��ջ�����ڵ�λ��
     z->zhansize=z->zhansize+Size;//��������ջ�Ĵ�С��������
  }
  *(z->top)=e;
    z->top++;
}
void Out(zhanlie *z,Elem *e)//��ջ�Ĳ���,����ָ��Ϳ���ֱ�ӶԵ�ַ���в���������ȥreturn�ˣ�
{
    if(z->top==z->end)//ջ�յ���˼;
        return 0;
    *e=*(--(z->top));//�����ΪʲôҪ����
}
void Clean(zhanlie *z)//ջ�����
{
    z->top=z->end;
}
void Destory(zhanlie *z)//����ջ
{
    int i,len;
    len = zhanlen(*z);
    for(i=0;i<len;i++) //�ײ��ƻ���
    {
        free(z->end);//�ͷſռ䣻
        z->end++;
    }
    z->top=z->end=NULL;
    z->zhansize=0;
}
int zhanlen(zhanlie *z)//�����ջ�ĵ�ǰ����
{
    return (z->top-z->end);
}
int main()
{
    /***********************

    **********���������������ʮ���Ƶ�ת��

    *******************************/
   zhanlie z;
   Elem c,a;
   int i,len,shi=0,zhu=0;
   creat(&z);
   printf("��������Ҫת���Ķ����Ƶ��������Իس�����\n");

   while((c=getchar())!='\n')//���������һ�����ַ���������롣
   {
       push(&z,c);
   }

   printf("\n��ǰ���ջ��ʵ������Ϊ:%d",zhanlen(&z));
   len=zhanlen(&z);
   for(i=0;i<len;i++)
   {
       Out(&z,&a);
       shi=shi+(int)(a-'0')*pow(2,i);
   }
   printf("\nʮ���Ƶı�﷽ʽΪ��%d",shi);




    return 0;
}
