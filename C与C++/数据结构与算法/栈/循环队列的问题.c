#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TURE 1
#define FAIL 0
#define MAXSIZE 100
/******************************************
�����������������ڣ����Ǻ������Ƿ����У������Ǹ����ݵĴ洢��ʽ��
         ѭ�����е�Ŀ���൱��һ��ԲȦ
         ����ͷָ����βָ���ڲ��ϱ仯
         ����������ԭ�����ڲ�ͬ��λ�ö����ݽ����޸ġ�
*******************************************/
typedef struct {
      int *a;
}Elemtype;
typedef struct {
        Elemtype *base;
        int front;
        int rear;
} Xunlie;
void Creat (Xunlie *z)//��
{
    z->base=(Elemtype )malloc(MAXSIZE*sizeof(Elemtype));
    if(!z->base) exit(0);
    z->front=z->rear=0;
}
void Insert(Xunlie *z,Elemtype e)//��
{
    if(z->front==z->rear+1) return;
    *(z->base->(a+z->rear))=e;
    z->rear=(z->rear+1)%MAXSIZE;
}
void Output(Xunlie *z,Elemtype *e)//��
{
    if(z->front+1==z->rear)
        return ;
    e=z->base->(a+z->rear);
    z->front=(z->front+1)%MAXSIZE;
}
