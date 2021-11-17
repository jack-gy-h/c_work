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


// 获取到location位置上的元素的值并返回给num
void GetElem(seqlist L, int location, int *num);


// 往数组的第location个位置插入数据元素num
void ListInsert(seqlist *L, int location, int num);

// 初始化并创建顺序表及展示
void InitAndCreate(seqlist *L, int *l);


// 往顺序表的最后一位上插入数据
void ListInsertLastLocation(seqlist *L, int location, int num);