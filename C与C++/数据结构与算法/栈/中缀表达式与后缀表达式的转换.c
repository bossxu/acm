#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 20
#define SIZEADD 10
/*******************************************
1��������������������Ǿ�ֱ�ӽ��������
2����������������������ǽ�����뵽ջ�У�����������ʱ����Ҳ�������ջ�С�
3���������һ�������ţ���ջԪ�ص������������Ĳ��������ֱ������������Ϊֹ��ע�⣬������ֻ�������������
4����������κ������Ĳ��������磨��+���� ��*�������������ȣ���ջ�е���Ԫ��ֱ���������ָ������ȼ���Ԫ��(����ջΪ��)Ϊֹ����������ЩԪ�غ󣬲Ž������Ĳ�����ѹ�뵽ջ�С���һ����Ҫע�⣬ֻ��������" ) "����������ǲŵ���" ( "������������Ƕ����ᵯ��" ( "��
5��������Ƕ����������ĩβ����ջ������Ԫ�����ε�����
������ԭ��
*******************************************************************/
 typedef char Elem;
typedef struct zhan//��������
{
    Elem *top;
    Elem *base;
    int size;
}Lie;
void creat(Lie *z)//��ջ
{
    z->base=(Elem *)malloc(SIZE*sizeof(Elem));   if(!z->base) exit(0);
    z->top=z->base;
    z->size=SIZE;
}
void Push(Lie *z,Elem a)//��ջ
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
void Pop(Lie *z,Elem *a)//��ջ
{
    if(z->top==z->base)
        return ;
    *a=*--(z->top);
}
int Lielen(Lie *z)//ջ������
{
    return ((z->top)-(z->base));
}
int main()
{
    Lie z;
    char c,e,shu[SIZE];
    int i=0,j;

    creat(&z);

    printf("��������Ҫת������׺���ʽ������#������\n");
    scanf("%c",&c);
    while(c!='#')//���ַ��ŵĲ���
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
            printf("�����ʽ�������ɵ��\n");
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
