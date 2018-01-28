#define MAXSIZE 100
typedef char Elemtype;


typedef struct Cnode//孩子的结点
{
    int child;                       //孩子节点的下表
    Cnode struct *next;      //指向下一个孩子的指针
}Node;

typedef struct//表头结构
{
    Elemtype date;
    int parents;                        //与前面的相呼应，表示指向双亲的位置
    Node *Firstchild;                //指向第一个对应的孩子
}Ctbox;

typedef struct //树的结构
{
    Ctbox SHU[MAXSIZE];
    int r,n;//表示节点的数和根目录
}
