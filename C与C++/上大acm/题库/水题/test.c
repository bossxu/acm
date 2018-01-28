#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
    int num;
    struct student *next;
}node;
node *insert(node *head,int m)
{
    if(head==NULL) head->num=m;
}
int main()
{
    int n,m,i,j;
    node *head;
    head=NULL;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);

        }
    }


    return 0;
}
