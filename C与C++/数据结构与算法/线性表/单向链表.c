#include<stdio.h>
#include<stdlib.h>
struct student
{
    int num;
    struct student *next;
};
struct student *insert(struct student *head,int num)
{
    struct student *p,*end;
    p=(struct student *)malloc(sizeof(struct student));
    p->num=num;
    p->next=NULL;
    if(head==NULL) head=p;
    else
    {for(end=head;end->next!=NULL;end=end->next);
    end->next=p;}
    return head;
}
int main()
{
    struct stduent *head;
    struct student *p;
    int num,n,i;
    head=NULL;
    //p=(struct student *)malloc(sizeof(struct student));
    printf("请输入要建立多大的链表：\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("请输入第%d个数据\n",i+1);
        scanf("%d",&num);
        head=insert(head,num);
    }
        for(p=head;p!=NULL;p=p->next)
       {

       printf("%d ",p->num);
       }



    return 0;
}
