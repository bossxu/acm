#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int num;
    struct student *next;
}node;
int main()
{
node *head;int i,it;
    head=NULL;
    while(1)

    {
        printf("��������Ҫ������:\n1:��ʼ������\n2:����һ������\n3:��������\n0:�˳�\n");
        scanf("%d",&it);
        if(it==0 ) break;
        switch(it)
        {
            case 1:xunlist(&head);shuchu(head);break;
            case 2:insert(head);break;
            case 3:shuchu(head);break;
        }

    }
    return 0;
}
void xunlist(node **head)//��ʼ��ѭ������
{
    node *temp;
    node *target;
    int item;
    printf("������ڵ��ֵ������0����\n");
    while(1)
    {
        scanf("%d",&item);
        if(item==0) break ;
        if(*head==NULL)
        {
            *head=(node *)malloc(sizeof(struct student));
            (*head)->num=item;
            (*head)->next=*head;
        }
        else
        {
            for(target=*head;target->next!=*head;target=target->next);
            temp=(node *)malloc(sizeof(struct student));
            temp->num=item;
           target->next=temp;
            temp->next=*head;

        }
    }
}
void shuchu(node *head)//�������Ԫ��
{
    node *p;p=head;
    printf("\n***************�����е�Ԫ����*************\n");
     do{
        printf("%d ",p->num);
        p=p->next;}while(p!=head);
        putchar('\n');
}
void insert(node *head)//����Ԫ�أ�
{
    int i,item,n;node *p;p=head;
    node *temp;
    printf("������Ҫ�����λ��\n");
    scanf("%d",&n);
    temp=(node *)malloc(sizeof(struct student));
    printf("������ֵ\n");scanf("%d",&item);
    temp->num=item;
    if(n==1)
    {
     for(p=head;p->next!=head;p=p->next);
     temp->next=head;
     p->next=temp;
     head=temp;
    }
    else
    {
        for (i=1;i<n-1;i++) p=p->next;
        temp->next=p->next;
        p->next=temp;
    }
}
