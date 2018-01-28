#include<stdio.h>
#include<stdlib.h>
struct student
{
    int num,score;
    struct student *next;
};

int main()
{

    struct student *head ,*p,*tail;
    int n;

    head=0;
    tail=0;
    scanf("%d",&n);
    while(n!=0)
    {
        p=(struct student *)malloc(sizeof(struct student));//释放空间
        scanf("%d%d",&(p->num),&(p->score));
        p->next=head;//表示这个节点的下个结点指向什么,指向头；
        head=p;//从现在起，p这个指针变成了新的指针
        n--;

    }//插入头的方法
    while(n!=0)
    {
        p=(struct student *)malloc(sizeof(struct student));
        scanf("%d%d",&(p->num),&(p->score));
        p->next=0;//既然插入尾，那么每次的 下一个都要指向空指针；
        if(head==0)
            head=p;//如果头指针为空，就把这个节点看成头的；
        else
            tail->next=p;//后面这两部，表示p1->next=p2;自己带着玩看看
        tail=p;
    n--;
    }//插入尾的方法
    for(p=head;p!=0;p=p->next)
  printf("%d %d",p->num,p->score);



    return 0;
}
