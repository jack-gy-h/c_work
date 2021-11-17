#include <stdio.h>

#include <stdlib.h>

#include "seqlisthead.h"

void MergeSeqList(seqlist *L1, seqlist *L2, seqlist *L3)
{

    int k = 0;

    int location2 = 0;

    for (int i = 0; i < L1->length; i++)
    {
        for (int j = location2; j < L2->length; j++)
        {
            if (L1->data[i] > L2->data[j])
            {
                ListInsertLastLocation(L3, ++k, L2->data[j]);

                // k++;

                showeach(*L3, k);
            }
            else
            {
                ListInsertLastLocation(L3, ++k, L1->data[i]);

                // k++;

                showeach(*L3, k);

                location2 = j;

                break;
            }
        }
    }

    if (location2 != (L2->length) - 1)
    {

        for (int p = location2; p < L2->length; p++)
        {
            ListInsertLastLocation(L3, k, L2->data[p]);

            k++;
        }
    }

    L3->length = k;
}

void MergeSeqList1(seqlist *L1, seqlist *L2, seqlist *L3)
{

    int k = 0;

    int location2 = 0;

    int i = 0;

    int j = location2;

    while (i < L1->length)
    {

        while (j < L2->length)
        {
            if (L1->data[i] > L2->data[j])
            {
                ListInsertLastLocation(L3, k, L2->data[j]);

                k++;

                showeach(*L3, k);
            }
            else
            {
                ListInsertLastLocation(L3, k, L1->data[i]);

                k++;

                showeach(*L3, k);

                location2 = j;

                break;
            }

            j++;
        }

        i++;
    }

    // for (int i = 0; i < L1->length; i++)
    // {
    //     for (int j = location2; j < L2->length; j++)
    //     {
    //         if (L1->data[i] > L2->data[j])
    //         {
    //             ListInsertLastLocation(L3, k, L2->data[j]);

    //             k++;

    //             showeach(*L3, k);
    //         }
    //         else
    //         {
    //             ListInsertLastLocation(L3, k, L1->data[i]);

    //             k++;

    //             showeach(*L3, k);

    //             location2 = j;

    //             break;
    //         }
    //     }
    // }

    if (location2 != (L2->length) - 1)
    {

        for (int p = location2; p < L2->length; p++)
        {
            ListInsertLastLocation(L3, k, L2->data[p]);

            k++;
        }
    }

    L3->length = k;
}

void MergeSeqList2(seqlist *L1, seqlist *L2, seqlist *L3)
{

    int i = 0;

    int j = 0;

    int k = 0;

    while (i<=((L1->length)-1) && j<=((L2->length)-1))
    {
        while (L1->data[i]>L2->data[j] && j<=((L2->length)-1))
        {
            ListInsertLastLocation(L3, k, L2->data[j]);

            k++;

            j++;
        }

        while (L1->data[i]<=L2->data[j] && i<=((L1->length)-1))
        {
            ListInsertLastLocation(L3, k, L1->data[i]);

            k++;

            i++;
        }
        
        
    }

    while (i<=((L1->length)-1))
    {
        ListInsertLastLocation(L3, k, L1->data[i]);

        k++;

        i++;
    }

    while (j<=L2->length-1)
    {
        ListInsertLastLocation(L3, k, L2->data[j]);

        k++;

        j++;
    }
    
    
    
}




// 当满足某个条件的时候就不比较了，用for循环已经无法准确或简单地表达出

// 想表达的意思了

// 因此使用while，当条件满足时，一直循环执行





// 当L1->data[i]>L2->data[j]时,将L2->data[j]插入到L3中

// 将比较的位数加一（j++）

// 否则的话，就将L1->data[i]插入到L3中

// 并将比较的位数加一（i++）

// 非此即彼，使用if..else..：

// if(L1->data[i]>L2->data[j])
//         {
//             ListInsertLastLocation(L3, k, L2->data[j]);

//             k++;

//             j++;
//         }else
//         {
//            ListInsertLastLocation(L3, k, L1->data[i]);

//             k++;

//             i++;
//         }





// 重复上面的操作，直至i或者j有一个越界

// 就结束 while (i<=((L1->length)-1) && j<=((L2->length)-1))

void MergeSeqList3(seqlist *L1, seqlist *L2, seqlist *L3)
{

    int i = 0;

    int j = 0;

    int k = 0;


    while (i<=((L1->length)-1) && j<=((L2->length)-1))
    {
        if(L1->data[i]>L2->data[j])
        {
            ListInsertLastLocation(L3, k, L2->data[j]);

            k++;

            j++;
        }else
        {
           ListInsertLastLocation(L3, k, L1->data[i]);

            k++;

            i++;
        }
        //  (L1->data[i]<=L2->data[j] && i<=((L1->length)-1))
        // {
        //     ListInsertLastLocation(L3, k, L1->data[i]);

        //     k++;

        //     i++;
        // }
        
        
    }

    while (i<=((L1->length)-1))
    {
        ListInsertLastLocation(L3, k, L1->data[i]);

        k++;

        i++;
    }

    while (j<=L2->length-1)
    {
        ListInsertLastLocation(L3, k, L2->data[j]);

        k++;

        j++;
    }
    
    
    
}

int main()
{

    int l1, l2;

    seqlist L1, L2, L3;

    InitAndCreate(&L1, &l1);

    InitAndCreate(&L2, &l2);

    Init(&L3);

    MergeSeqList3(&L1, &L2, &L3);

    printf("合并后的顺序表为：\n");

    show(L3);

    system("pause");
}