#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Elem;
typedef struct  Student {//前面的是队列创建的条件，表示不是很懂那个下面的student在下面的意义。
          Elem date;
          struct Student *next;
}Student,*Stu;
typedef struct {//这里的意义在于真正的创建一个队列的形式，这个队列的元素都用了前面定义的目标Student
   Stu front,rear;
}Link;
void creat(Link *z)//创建一个新的队列
{
    z->front=z->rear=(Stu)malloc(sizeof(Student));
    if(!z->front) exit(0);
    z->rear->next=NULL;
}
void Getin(Link *z,Elem e)//进队列
{
    Stu p;//这里没有用到* p的原因是，我在之前的定义说过 *Stu所以，这里其实已经说明p是一个指针
    p=(Stu)malloc(sizeof(Student));//malloc前面的括号表示的是p的格式，如果我前面定义的是char *p；那么前面括号里面的就是char *；
    p->date=e;
    p->next=NULL;
    z->rear->next=p;
    z->rear=p;
}
void Getout(Link *z,Elem *e)//出队列
{
    Stu p;
    if(z->front==z->rear)
        return ;
    p=z->front->next;//因为这里的头指针是空的；
    *e=p->date;
    z->front->next=p->next;
    if(p==z->rear)
        z->rear=z->front;
    free(p);//这样的话，我的头指针一直为空，删除的是头指针的下一个指针；
}
void Destory(Link *z)
{
    //重头删
    while(z->front){
     z->rear=z->front->next;
     free(z->front);
     z->front=z->rear;
    }
}
int Pan(Link *z)
{
    if(z->front==z->rear)
        return 0;
    else
        return 1;
}
int main()
{
    int i=0,j,k;
    char c,e;
    Link head;
    creat(&head);
    printf("请输入一串字符，并以#结束\n");
    while((c=getchar())!='#')
    {
        Getin(&head,c);
    }
    while(Pan(&head))
    {
        Getout(&head,&e);
        printf("%c",e);
    }
    return 0;
}
