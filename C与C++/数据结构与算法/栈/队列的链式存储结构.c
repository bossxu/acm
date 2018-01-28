#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Elem;
typedef struct  Student {//ǰ����Ƕ��д�������������ʾ���Ǻܶ��Ǹ������student����������塣
          Elem date;
          struct Student *next;
}Student,*Stu;
typedef struct {//������������������Ĵ���һ�����е���ʽ��������е�Ԫ�ض�����ǰ�涨���Ŀ��Student
   Stu front,rear;
}Link;
void creat(Link *z)//����һ���µĶ���
{
    z->front=z->rear=(Stu)malloc(sizeof(Student));
    if(!z->front) exit(0);
    z->rear->next=NULL;
}
void Getin(Link *z,Elem e)//������
{
    Stu p;//����û���õ�* p��ԭ���ǣ�����֮ǰ�Ķ���˵�� *Stu���ԣ�������ʵ�Ѿ�˵��p��һ��ָ��
    p=(Stu)malloc(sizeof(Student));//mallocǰ������ű�ʾ����p�ĸ�ʽ�������ǰ�涨�����char *p����ôǰ����������ľ���char *��
    p->date=e;
    p->next=NULL;
    z->rear->next=p;
    z->rear=p;
}
void Getout(Link *z,Elem *e)//������
{
    Stu p;
    if(z->front==z->rear)
        return ;
    p=z->front->next;//��Ϊ�����ͷָ���ǿյģ�
    *e=p->date;
    z->front->next=p->next;
    if(p==z->rear)
        z->rear=z->front;
    free(p);//�����Ļ����ҵ�ͷָ��һֱΪ�գ�ɾ������ͷָ�����һ��ָ�룻
}
void Destory(Link *z)
{
    //��ͷɾ
    while(z->front){
     z->rear=z->front->next;
     free(z->front);
     z->front=z->rear;
    }
}
int Pan(Link *z)
{
    if(z->front==z->rear)
        return 0;
    else
        return 1;
}
int main()
{
    int i=0,j,k;
    char c,e;
    Link head;
    creat(&head);
    printf("������һ���ַ�������#����\n");
    while((c=getchar())!='#')
    {
        Getin(&head,c);
    }
    while(Pan(&head))
    {
        Getout(&head,&e);
        printf("%c",e);
    }
    return 0;
}
