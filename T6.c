#include <stdio.h>
#include <stdlib.h>
#include "seqlisthead.h"

// 注意事项，移位要考虑到每一位

// 这里不小心忽略了最后一位

// 当对比的两个元素相同的时候，相同位计数变量加一(k++)

// 当不相同时，将后一位移动到最终位置上(L->data[(i +1)- k] = L->data[i+1];)

// 最后再处理一下顺序表的长度(L->length = L->length - k;)

void delete_the_same(seqlist *L)
{

    int k = 0;

    for (int i = 0; i < L->length - 1; i++)
    {
        if (L->data[i] == L->data[i + 1])
        {
            k++;
        }
        else
        {
            L->data[(i + 1) - k] = L->data[i + 1];
        }

        showeach(*L, i + 1);
    }

    // L->data[(L->length) - 1 - k] = L->data[L->length - 1];

    L->length = L->length - k;
}

int main()
{

    int l;

    int num;

    seqlist L;

    Init(&L);

    printf("请输入顺序表的长度：\n");

    scanf("%d", &l);

    printf("请输入顺序表：\n");

    create(&L, l);

    printf("创建的顺序表为：\n");

    show(L);

    printf("\n");

    // for (int i = 1; i <= L.length; i++)
    // {
    //     GetElem(L, i, &num);
    // }

    // printf("第一次插入元素后的顺序表为：\n");

    // ListInsert(&L, 3, 22);

    // show(L);

    // printf("\n");

    delete_the_same(&L);

    printf("删除后的顺序表为：\n");

    show(L);

    system("pause");
}
