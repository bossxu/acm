#include<stdio.h>
#include<stdlib.h>
struct student
{
    int num;
    struct student *next;
};
struct student* creat(struct student *head,int num)//���뷨д������ͷ�巨
{
    struct student *p;
    p=(struct student *)malloc(sizeof(struct student));
    p->num=num;
    p->next=head;
    head=p;
}
int main()
{
    struct student *p1,*p2,*head;
    head=NULL;
    int i,num,item;
    for(i=0;i<20;i++)
    {
        num=(int)rand()%100;
        head=creat(head,num);
        //printf("%d ",num);
    }
    while(1)
    {
    printf("20�����Ѿ����ɣ���ѡ�����\n 1���������� 2��Ѱ��������м�ֵ�� 3���˳� ");
    scanf("%d",&item);
    switch(item){

   case 1 :    for(p1=head;p1!=NULL;p1=p1->next)//����
              printf("%d ",p1->num);
              putchar('\n');break;
   case 2 :      for(p1=head,p2=head;p1!=NULL;p1=p1->next->next,p2=p2->next); printf("%d \n",p2->num);break;
    }
    if(item==3) {printf("лл����"); break;}
   }

    return 0;
}
