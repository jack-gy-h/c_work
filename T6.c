#include <stdio.h>
#include <stdlib.h>
#include "seqlisthead.h"


// 注意事项，移位要考虑到每一位

// 这里不小心忽略了最后一位


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
            L->data[i - k] = L->data[i];
        }

        showeach(*L, i + 1);
    }

    L->data[(L->length) - 1 - k] = L->data[L->length - 1];

    L->length = L->length - k;
}

int main()
{

    int l;

    seqlist L;

    Init(&L);

    printf("请输入顺序表的长度：\n");

    scanf("%d", &l);

    printf("请输入顺序表：\n");

    create(&L, l);

    printf("创建的顺序表为：\n");

    show(L);

    printf("\n");

    delete_the_same(&L);

    printf("删除后的顺序表为：\n");

    show(L);

    system("pause");
}
