//删除顺序表中最小的元素并由最后一个元素填补

// 原始版本
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#define initsize 100

typedef int Datatype;

typedef struct
{


    //结构体基础：《C Primer Plus(第6版) 中文版》P441

    //指向data数组的组首元素的值
    
    Datatype *data;

    int n; //当前长度；

    int maxsize; //最大容量；

} seqlist;

void Init(seqlist *L)

{
    
    //指针基础：《C Primer Plus(第6版) 中文版》 P267-275

    // malloc基础：《C Primer Plus(第6版) 中文版》P396

    //sizeof:《C Primer Plus(第6版) 中文版》 P113

    // 启示及注意事项：《C Primer Plus(第6版) 中文版》P297-298

    // 创建一个指针时，系统只分配了储存指针本身的内存，并未分配储存数据的内存。

    // 因此：

    //指针使用说明：

    //1.声明

    //2.为指针分配数据的地址

    // 再使用




    
    //*找出地址中的值

    // ∴ * + 地址（or指针）

    // & ＋ 变量

    //&找出变量中的地址
   
    
    L->data = (Datatype *)malloc(sizeof(Datatype) * initsize); //动态分配；
    
    L->n = 0;

    L->maxsize = initsize;
}

void creat(seqlist *L, int n)

{
    for (int i = 0; i < n; i++)

    {
        scanf("%d", &(L->data[i]));

        L->n = n;
    }
}

void removemin(seqlist *L, int *count)

{
    int i, pos = 0;

    for (i = 2; i <= L->n; i++)

    {
        if ((L->data[i - 1])<L->data[pos])

            pos = i - 1;
    }

    *count = L->data[pos];

    //L->n--;

    L->data[pos] = L->data[(L->n)-1];
}

void show(seqlist L)

{
    for (int i = 0; i < L.n; i++)

    {
        printf("%d ", L.data[i]);
    }
}

int main()

{
    //从顺序表中删除具有最小值的元素并由函数返回被删元素的值

    int n, back;

    seqlist L;

    Init(&L);

    printf("请输入你想创建的长度：");

    scanf("%d", &n);

    printf("请输入初始值：");

    creat(&L, n);

    printf("你创建的顺序表是：\n");

    show(L);

   // printf("\n%d",L.data[0]);//printf全面的内容是输出的内容，后面为替换的内容，用于替换掉双引号内的%?的内容

    removemin(&L, &back);

    printf("\n最小值为：%d", back);

    printf("\n删除后的顺序表是：\n");

    show(L);

    system("pause");
}