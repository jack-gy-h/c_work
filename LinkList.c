#include <stdio.h>

#include <stdlib.h>

#include "LinkList.h"

#define random 10

// 初始化思路：初始化结构体内的每一个变量

void Init(LinkList L)
{

    L->data = random;

    L->next = NULL;
}

// 创建链表的思路：

// 将每一个输入的数据写到一个新的节点中，再插入到链表中

// 具体实现：

// 先用指针初始化一个结点

// p = (LinkList)malloc(random * sizeof(LNode));

// p->data = 0;

// p->next = NULL;

// 然后利用scanf函数将数据写到节点的data域中：

//   scanf("%d", &(p->data));

// 将结点接到头节点后面：

// p->next = L->next;

// L->next = p;

// 这种做法出来的链表正向遍历时所得的是输入时数据的逆序；

void create(LinkList L, int n)
{

    LinkList p;

    for (int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(random * sizeof(LNode));

        p->data = 0;

        p->next = NULL;

        scanf("%d", &(p->data));

        p->next = L->next;

        L->next = p;
    }
}



// 创建链表的思路：

// 将每一个输入的数据写到一个新的节点中，再插入到链表中

// 具体实现：

// 先用指针初始化一个结点

// p = (LinkList)malloc(random * sizeof(LNode));

// p->data = 0;

// p->next = NULL;

// 然后利用scanf函数将数据写到节点的data域中：

//   scanf("%d", &(p->data));

// 这里主要是将结点接上后，将头指针移动到最后一个结点的位置上再进行插入：

// 将结点接上后：

// L->next = p;

// 将头指针移动到最后一个结点的位置上

// L = L->next;
void create1(LinkList L, int n)
{

    LinkList p;

    for (int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(random * sizeof(LNode));

        p->data = 0;

        p->next = NULL;

        scanf("%d", &(p->data));

        L->next = p;

        L = L->next;
    }
}








// 从第一个结点（非头结点）开始遍历，则需要将传入的头指针指向下一位

// 以便让非头结点的结点作为遍历的第一位：

// L = L->next;

// 然后输出数据：

// printf("%d ", L->data);

void show(LinkList L, int n)
{

    // LinkList p;

    // p = (LinkList)malloc(random * sizeof(LNode));

    // L = L->next;

    for (int i = 0; i < n; i++)
    {
        L = L->next;

        printf("%d ", L->data);
    }
}