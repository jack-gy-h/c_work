#include <stdio.h>

#include <stdlib.h>

#include "LinkList.h"

#define size 100

int main()
{

    LinkList L;

    int n;

    L = (LinkList)malloc(size * sizeof(LNode));

    Init(L);

    printf("请输入您想创建的长度:");

    scanf("%d", &n);

    printf("请输入您想添加的数据:");

    create1(L, n);

    printf("你创建的链表表是:\n");

    show(L,n);

    system("pause");
}