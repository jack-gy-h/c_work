#include <stdio.h>

#include <stdlib.h>

#include "seqlisthead.h"


// 直接使用结果法进行计算，不过移动了pos + (L->length - lastpos - 2) +1

// 而delete1先找两个元素的位置再进行移动，则只移动了(L->length - lastpos - 2) +1 个位置

// 而遍历的次数是一样的，因此delete1的效率更高


void delete (seqlist *L, int s, int t)
{

    int k = 0;

    for (int i = 0; i < L->length; i++)
    {

        if (L->data[i] < s || L->data[i] > t)
        {

            k++;

            L->data[k - 1] = L->data[i];
        }
    }

    L->length = k;
}


// 核心思想：由于是有序表，因此只需要找到开头和结尾的两个数的位置（即找到相应的数组下标）

// 并记录下来，直接开始移动即可
void delete1(seqlist *L, int s, int t)
{

    int pos, lastpos;

    for (int i = 0; i < L->length; i++)
    {

        if (L->data[i] == s)
        {

            pos = i;
        }

        if (L->data[i] == t)
        {
            lastpos = i;

            break;
        }
    }

    for (int p = 0; p <= (L->length - lastpos - 2); p++)
    {
        L->data[pos + p] = L->data[(lastpos + 1) + p];
    }

    L->length = pos + (L->length - lastpos - 2) +1;
}

int main()
{

    int l, s, t;

    seqlist L;

    Init(&L);

    printf("请输入顺序表的长度：\n");

    scanf("%d", &l);

    printf("请输入顺序表：\n");

    create(&L, l);

    printf("创建的顺序表为：\n");

    show(L);

    printf("\n");

    printf("请输入要删除的值的区间：（格式为s t,并且要求s < t）\n");

    scanf("%d %d", &s, &t);

    delete1(&L, s, t);

    printf("删除后的顺序表为：\n");

    show(L);

    system("pause");
}