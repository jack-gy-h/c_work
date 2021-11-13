
#include <stdio.h>

#include <stdlib.h>

// #define用法：《C Primer Plus(第6版) 中文版》P522

// #define int ElemType;

// typedef用法:《C Primer Plus(第6版) 中文版》P478

#define initsize 100

typedef int ElemType;

typedef struct T2
{
    // 因此此处定义的新类型ElemType应用typedef来定义

    ElemType *elem;

    int length; //当前长度

    int listsize; //最大长度

} seqlist;

void Init(seqlist *L)
{

    L->elem = (ElemType *)malloc(initsize * sizeof(ElemType));

    L->length = 0;

    L->listsize = initsize;
}


// 写入数据和数组的长度以备后用
void create(seqlist *L, int n)
{

    for (int i = 0; i < n; i++)
    {

        scanf("%d", &(L->elem[i]));
    }

    L->length = n;

}



void show(seqlist L){

    for (int i = 0; i < L.length;i++){

        printf("%d ", L.elem[i]);
    }

    printf("\n");
}

void show1(seqlist L,int number){

    printf("第%d次转置后的顺序表：\n",number);

    for (int i = 0; i < L.length;i++){


        printf("%d ", L.elem[i]);
    }

    printf("\n");
}

void transposition(seqlist *L){

    int number;
// 关键错误：使用了数组的[-1]

// 不能使用的原因，在初始化elem指针的时候给他分配了100个空间

// 因此-1对应的是第100个位置而不是输入数组的最后一个位置

// 因为数组不是填满分配的所有的空间的

// 因此数组的最后以为应该用(L->length)-1来获取
    for (int i = 0;i< (int) (L->length/2) ; i++){

        number = L->elem[i];

        L->elem[i] = L->elem[(L->length)-1-i];

        L->elem[(L->length)-1-i] = number;

        show1(*L, i+1);
    }
}

int main()
{
    int n;

    seqlist L;

    Init(&L);

    printf("请输入您想创建的长度：\n");

    // scanf基础：《C Primer Plus(第6版) 中文版》P92

    // scanf赋值的后一个变量是直接将值赋值到相应的指针上，原理和原因同指针的使用（非return方法修改传入值）

    scanf("%d", &n);

    printf("请输入您想创建的顺序表：\n");

    create(&L, n);

    printf("你创建的顺序表是:\n");

    show(L);

    transposition(&L);

    printf("转置后的顺序表为：\n");

    show(L);

    system("pause");
}