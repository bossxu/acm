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
        p=(struct student *)malloc(sizeof(struct student));//�ͷſռ�
        scanf("%d%d",&(p->num),&(p->score));
        p->next=head;//��ʾ����ڵ���¸����ָ��ʲô,ָ��ͷ��
        head=p;//��������p���ָ�������µ�ָ��
        n--;

    }//����ͷ�ķ���
    while(n!=0)
    {
        p=(struct student *)malloc(sizeof(struct student));
        scanf("%d%d",&(p->num),&(p->score));
        p->next=0;//��Ȼ����β����ôÿ�ε� ��һ����Ҫָ���ָ�룻
        if(head==0)
            head=p;//���ͷָ��Ϊ�գ��Ͱ�����ڵ㿴��ͷ�ģ�
        else
            tail->next=p;//��������������ʾp1->next=p2;�Լ������濴��
        tail=p;
    n--;
    }//����β�ķ���
    for(p=head;p!=0;p=p->next)
  printf("%d %d",p->num,p->score);



    return 0;
}
