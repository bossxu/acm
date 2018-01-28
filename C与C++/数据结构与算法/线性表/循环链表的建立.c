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
        printf("请输入你要做的事:\n1:初始化链表\n2:插入一个数据\n3:遍历链表\n0:退出\n");
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
void xunlist(node **head)//初始化循环链表；
{
    node *temp;
    node *target;
    int item;
    printf("请输入节点的值，并以0结束\n");
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
void shuchu(node *head)//输出链表元素
{
    node *p;p=head;
    printf("\n***************链表中的元素有*************\n");
     do{
        printf("%d ",p->num);
        p=p->next;}while(p!=head);
        putchar('\n');
}
void insert(node *head)//插入元素；
{
    int i,item,n;node *p;p=head;
    node *temp;
    printf("请输入要插入的位置\n");
    scanf("%d",&n);
    temp=(node *)malloc(sizeof(struct student));
    printf("请输入值\n");scanf("%d",&item);
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
