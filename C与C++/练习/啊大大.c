#include<stdio.h>
struct student
{
    int id,year;
    char name [10];
    int number[11];
    struct student *next;
};
int main()
{
    int n,i,j;
    scanf("%d",&n);
    struct student *p,*head,*end;
    head=0;end=0;
    while(n!=0)
    {
     scanf("%d%d%s%s",&(p->id),&(p->year),p->name,p->number);
     /*p->next=head;
     head=p;*/
     p->next=0;
     if(head=0)
        head=p;
     else
        end->next=p;
     end=p;



     n--;


    }
    return 0;
}
