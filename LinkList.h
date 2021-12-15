#include<string.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;

// 这里的LinkList对应的时引用了struct上的变量名

// 用typedef定义的结构体别名只能在该定义后面使用

// 在结构体内对自己进行引用时，需要引用结构体的名字而不是typedef定义的别名（相当于typedef还没生效）

    struct LNode *next;

}LNode ,*LinkList;

void Init(LinkList L);

void create(LinkList L, int n);

void create1(LinkList L, int n);

void show(LinkList L ,int n);

// typedef struct
// {
//     char *pItem;
//     struct pNo *pNext;
// } pNode1,*pNode;
