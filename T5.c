#include <stdio.h>

#include <stdlib.h>

#include "seqlisthead.h"


// 结果法中记录不在范围内的个数(即为删除后顺序表中的个数or长度)：

// 当遇到不在范围内的元素时，计数变量要＋1（k++）

// 并且将该元素放到最终位置上，即k-1的位置上。(L->data[k-1] = L->data[i])

// 最后再更新顺序表的长度即可(L->length = k);

void delete (seqlist *L, int s, int t)
{

    int k = 0;

    // int num = 0;

    // int b;

    // printf("%d %d %d\n", s, t, t - s + 1);

    // int b = t -s + 1;

    // int a[b];

    // for (int i = 0; i < b; i++)
    // {
    //     a[i] = s + num;

    //     printf("第%d次操作后的数组为：%d\n", i+1, a[i]);

    //     num++;
    // }

    // for (int p = 0; p < L->length; p++)
    // {
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] < s || L->data[i] > t)
        {

            k++;

            L->data[k - 1] = L->data[i];

            // showeach(*L, k);
        }
    }

    L->length = k;
}

// 结果法中的记录在范围内的元素

// 按顺序遍历时，需要先看在范围内的元素，遇到则计数元素+1(k++)

// 如果遇到不在范围内的元素，则让它直接到达最终位置

// 方法：找到最终位置，并赋值给它(由于只遍历一次，因此可以改变遍历过的位置的值)

// 此时，最终位置应该在当前位置的前k个上（因为前面要删除k个在范围内的元素）（即L->data[i-k]=L->data[i]）

// 最后再更新下顺序表的长度即可(L->length = L->length - k)

void delete1(seqlist *L, int s, int t)
{

    int k = 0;

    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] >= s && L->data[i] <= t)
        {
            k++;
        }
        else
        {
            L->data[i - k] = L->data[i];
        }
    }

    L->length = L->length - k;
}

int main()
{

    int n, s, t;

    seqlist L;

    Init(&L);

    printf("请输入顺序表的长度：\n");

    scanf("%d", &n);

    printf("请输入顺序表:\n");

    create(&L, n);

    printf("创建的顺序表为：\n");

    show(L);

    printf("\n");

    printf("请输入要删除的值的区间：（格式为s t,并且要求s < t）\n");

    scanf("%d %d", &s, &t);

    delete1 (&L, s, t);

    printf("删除后的顺序表为：\n");

    show(L);

    system("pause");
}