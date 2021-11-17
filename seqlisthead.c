#include <stdio.h>

#include <stdlib.h>

#include "seqlisthead.h"

#define initsize 100

void Init(seqlist *L)
{

    L->data = (DataType *)malloc(initsize * sizeof(DataType)); //为data指针分配内存

    L->length = 0;

    L->allocationsize = initsize;
}

void create(seqlist *L, int l)
{

    for (int i = 0; i < l; i++)
    {

        scanf("%d", &(L->data[i]));
    }
    L->length = l;
}

void show(seqlist L)
{

    for (int i = 0; i < L.length; i++)
    {

        printf("%d ", L.data[i]);
    }
}

void showeach(seqlist L, int number)
{

    printf("第%d次变化后的顺序表：\n", number);

    for (int i = 0; i < L.length; i++)
    {

        printf("%d ", L.data[i]);
    }

    printf("\n");
}

void GetElem(seqlist L, int location, int *num)
{

    *num = L.data[location - 1];

    printf("获取到的第%d个位置上的元素为：%d\n", location, *num);
}

void ListInsert(seqlist *L, int location, int num)
{

    L->length++;

    for (int i = L->length - 1; i >= location; i--)
    {
        L->data[i] = L->data[i - 1];
    }

    L->data[location - 1] = num;
}

void InitAndCreate(seqlist *L, int *l)
{

    Init(L);

    printf("请输入顺序表的长度：\n");

    scanf("%d", l);

    printf("请输入顺序表：\n");

    create(L, *l);

    printf("创建的顺序表为：\n");

    show(*L);

    printf("\n");
}

void ListInsertLastLocation(seqlist *L, int location, int num){

    L->length++;

    L->data[location] = num;
}