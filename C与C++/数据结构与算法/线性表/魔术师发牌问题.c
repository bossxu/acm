#include<stdio.h>
#include<stdlib.h>
typedef struct pai
{
    int pian;
    struct pai *next;

}ka;
void Xlist(ka **head)
{
    ka *pa,*pb;
    pa=(*head);
     int i;
    (*head)->next=*head;
    for(i=0;i<12;i++)
    {
        pb=(ka *)malloc(sizeof(struct pai));
        for(pa=(*head);pa->next!=(*head);pa=pa->next);
        pb->next=pa->next;
        pa->next=pb;
        pb->pian=0;
    }
}
int main()
{
    ka *head,*pa,*q;
    head=(ka *)malloc(sizeof(struct pai));
    Xlist(&head);head->pian=1;
    int i,j,k=0;

    for(i=2;i<14;i++)
    {
        pa=head;
        for(j=0;j<i;j++)
        {
            pa=pa->next;
            if(pa->pian!=0) j--;

        }
        pa->pian=i;

    }
    pa=head;i=0;
do{
    printf("µÚ%dÕÅÅÆÎª£º%3d\n",++i,pa->pian);pa=pa->next;
}while(pa!=head);


    return 0;
}
