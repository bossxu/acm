#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 20
#define SIZEADD 10
/*******************************************
1）如果遇到操作数，我们就直接将其输出。
2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
4）如果遇到任何其他的操作符，如（“+”， “*”，“（”）等，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。弹出完这些元素后，才将遇到的操作符压入到栈中。有一点需要注意，只有在遇到" ) "的情况下我们才弹出" ( "，其他情况我们都不会弹出" ( "。
5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。
这个题的原理；
*******************************************************************/
 typedef char Elem;
typedef struct zhan//申明类型
{
    Elem *top;
    Elem *base;
    int size;
}Lie;
void creat(Lie *z)//建栈
{
    z->base=(Elem *)malloc(SIZE*sizeof(Elem));   if(!z->base) exit(0);
    z->top=z->base;
    z->size=SIZE;
}
void Push(Lie *z,Elem a)//进栈
{
    if((z->top-z->base)>=z->size)
    {
     z->base=(Elem *)realloc(z->base,(z->size+SIZEADD)*sizeof(Elem));
     if(!z->base) exit(0);
     z->top=z->base+z->size;
     z->size=z->size+SIZEADD;
    }
    *(z->top)=a;
    z->top++;
}
void Pop(Lie *z,Elem *a)//出栈
{
    if(z->top==z->base)
        return ;
    *a=*--(z->top);
}
int Lielen(Lie *z)//栈的容量
{
    return ((z->top)-(z->base));
}
int main()
{
    Lie z;
    char c,e,shu[SIZE];
    int i=0,j;

    creat(&z);

    printf("请输入你要转换的中缀表达式：并以#结束：\n");
    scanf("%c",&c);
    while(c!='#')//各种符号的操作
    {
        if(isdigit(c))
        {
        while(isdigit(c))
        {
            shu[i++]=c;
            shu[i]='\0';
            scanf("%c",&c);
        }
        printf("%d ",atoi(shu));
        }
         if(c==')')
        {
            Pop(&z,&e);
            while(e!='(')
            {
                printf("%c ",e);
                Pop(&z,&e);
            }
        }
        else if(c=='+'||c=='-')
        {
            if(!Lielen(&z))
                Push(&z,c);
            else
            {
           do
             {
                 Pop(&z,&e);
                if(e=='(')
                {
                    Push(&z,e);
                }
                else
                    printf("%c ",e);
             } while(Lielen(&z)&&e!='(');
             Push(&z,c);
            }
        }
        else if(c=='*'||c=='/'||c=='(')
        {
            Push(&z,c);
        }
        else if(c=='#')
            {
                break;
            }
        else
        {
            printf("输入格式错误，你个傻逼\n");
            //return -1;
        }
          scanf("%c",&c);
          i=0;
    }
    while(Lielen(&z))
    {
        Pop(&z,&e);
        printf("%c ",e);
    }

    return 0;
}
