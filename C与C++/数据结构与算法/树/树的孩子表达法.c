#define MAXSIZE 100
typedef char Elemtype;


typedef struct Cnode//���ӵĽ��
{
    int child;                       //���ӽڵ���±�
    Cnode struct *next;      //ָ����һ�����ӵ�ָ��
}Node;

typedef struct//��ͷ�ṹ
{
    Elemtype date;
    int parents;                        //��ǰ������Ӧ����ʾָ��˫�׵�λ��
    Node *Firstchild;                //ָ���һ����Ӧ�ĺ���
}Ctbox;

typedef struct //���Ľṹ
{
    Ctbox SHU[MAXSIZE];
    int r,n;//��ʾ�ڵ�����͸�Ŀ¼
}
