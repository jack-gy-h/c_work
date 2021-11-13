#include<stdio.h>

#include<stdlib.h>

#include"seqlisthead.h"

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

void showeach(seqlist L,int number){

    printf("第%d次变化后的顺序表：\n",number);

    for (int i = 0; i < L.length;i++){


        printf("%d ", L.data[i]);
    }

    printf("\n");
}