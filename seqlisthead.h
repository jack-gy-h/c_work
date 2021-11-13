#include<string.h>

typedef int DataType;

typedef struct
{
    DataType *data;

    int length; //当前长度

    int allocationsize; //分配的最大长度
} seqlist;

// 初始化顺序表
void Init(seqlist *L);

// 创建顺序表
void create(seqlist *L, int l);

// 展示顺序表
void show(seqlist L);

// 展示顺序表的第i次变化的情况
void showeach(seqlist L, int number);