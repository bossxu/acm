#include<stdio.h>
#include<stdlib.h>
typedef struct people
{
    int num;
    struct people *next;
}man;
void Xlist(man **head,int n)
{
    int i=1,j;
    man *end,*temp;
    end=*head;

    for(j=0;j<n;j++,i++)
    {
        if(*head==NULL)
        {
            (*head)=(man *)malloc(sizeof(struct people));
            (*head)->num=i;
            (*head)->next=(*head);
        }
        else
        {
            temp=(man *)malloc(sizeof(struct people));
            for(end=(*head);end->next!=(*head);end=end->next);
            temp->num=i;
            temp->next=end->next;
            end->next=temp;
        }
    }
}
/*void shuchu(man *head)
{  man *p;p=head;
    do{printf("%3d",p->num);p=p->next;} while(p!=head);
}*/
int main()
{
    man *head,*p,*q;int n;
    head=NULL;
    printf("请输入玩游戏的人的数目：\n");
    scanf("%d",&n);
    Xlist(&head,n);
    int i=2,j,it=0;
    p=head;
    while(it!=n-1)
    {
        p=p->next;q=p->next;
        i++;
        if(i%3==0)
        {
                printf("%3d",q->num);
                p->next=q->next;
                free(q);
                i++;
                it++;
        }

    }
    printf("\n");
printf("最后一个人的序号是：%d",p->num);

    return 0;
}
