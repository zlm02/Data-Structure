#include <stdio.h>
#define maxsize 100
typedef int ElementType; //可以直接修改顺序表数据类型。

typedef struct {
    ElementType data[maxsize];
    int length;
}SeqList;
//初始化。
void initList(SeqList *L)
{
    L->length=0;
}
//添加元素。成功返回1，失败返回0；
int appendElement(SeqList *L,ElementType num)
{
    if (L->length==maxsize) {
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length++]=num;
    return 1;
}
//遍历顺序表。
void showList(SeqList *L) {
    for (int i=0;i<L->length;i++) {
        printf("%d  ",L->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList L;
    initList(&L);
    printf("初始化成功，目前长度为%d\n",L.length);
    printf("占用内存%zu字节\n",sizeof(L.data));
    appendElement(&L,10);
    appendElement(&L,20);
    appendElement(&L,30);
    appendElement(&L,40);
    showList(&L);
    return 0;
}


