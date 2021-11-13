#include <stdio.h>

#include <stdlib.h>

#include "seqlisthead.h"

// #define initsize 100

// typedef int DataType;

// typedef struct T3
// {
//     DataType *data;

//     int length; //当前长度

//     int allocationsize; //分配的最大长庄1�7
// } seqlist;

// void Init(seqlist *L)
// {

//     L->data = (DataType *)malloc(initsize * sizeof(DataType)); //为data指针分配内存

//     L->length = 0;

//     L->allocationsize = initsize;
// }

// void create(seqlist *L, int l)
// {

//     for (int i = 0; i < l; i++)
//     {

//         scanf("%d", &(L->data[i]));
//     }
//     L->length = l;
// }

// void show(seqlist L)
// {

//     for (int i = 0; i < L.length; i++)
//     {

//         printf("%d ", L.data[i]);
//     }
// }

// 遍历了很多次

// 时间复杂度为O（n²）
void delete (seqlist *L, int n)
{

    int init_length = L->length;

    int num = 0;

    for (int i = 0; i < L->length; i++)
    {

        if (L->data[i] == n)
        {
            num++;
        }
    }
    for (int p = 1; p <= num; p++)
    {

        for (int q = 0; q < L->length; q++)
        {

            if (L->data[q] == n)
            {

                for (int r = q; r < (L->length) - 1; r++)
                {

                    L->data[r] = L->data[r + 1];
                }

                L->length--;

                showeach(*L, init_length - (L->length));

                break;
            }
        }
    }
}


// 按照要求只能遍历一遍

// 思路：

// 从最终结果出发，统计出顺序表的长度（即统计非删除值的个数）和直接得出最终顺序表列表并展示出来

// 当遇到非删除值时(L->data[i]!=n)，可以用一个值(这里使用了k，并给k赋值为0)

// 来进行计数加一(k++))

// 与此同时将第一个非删除值赋值给第一个位置(L->data[0]=L->data[i])

                                        //    L->data[1]=L->data[i+1]

                                         //    L->data[2]=L->data[i+5]

                                         //    L->data[3]=L->data[i+9]

 //  因为只能遍历一次，因此可更改值必在i及之前
 
 
//  前面的值不会再被使用（即可以任意更改）

//  因此遇到第k个非删除值时（k++表示非删除值+1）应写在L->data[k-1]上(因为数组从0开始)

void delete1(seqlist *L,int n){

    int k = 0;

    for (int i = 0; i < L->length;i++){

        if(L->data[i] != n ){
             
            k++;

            L->data [k-1]= L->data[i];

            
        }
    }

    L->length = k;
}

int main()
{

    int l; //输入的数组长度

    int n; //要删除的数字

    seqlist L;

    Init(&L);

    printf("请输入顺序表的长度：\n");

    scanf("%d", &l);

    printf("请输入顺序表：\n");

    create(&L, l);

    printf("创建的顺序表为：\n");

    show(L);

    printf("\n");

    printf("待删除的值为：\n");

    scanf("%d", &n);

    delete1 (&L, n);

    printf("操作后的顺序表为：\n");

    show(L);

    system("pause");
}