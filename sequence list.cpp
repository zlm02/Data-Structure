#include <stdio.h>
#define maxsize 100
typedef int ElementType; //可以直接修改顺序表数据类型。

typedef struct {
    ElementType data[maxsize];
    int length;
} SeqList;

//初始化。
void initList(SeqList *L) {
    L->length = 0;
}

//添加元素。成功返回1，失败返回0；
int appendElement(SeqList *L, ElementType num) {
    if (L->length == maxsize) {
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length++] = num;
    return 1;
}

//遍历顺序表。
void showList( SeqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d  ", L->data[i]);
    }
    printf("\n");
}

//插入数据，pos代表插入位置，插入成功返回1失败返回0.
int insertElement(SeqList *L, int pos, ElementType num) {
    if (L->length == maxsize) {
        printf("已经满了\n");
        return 0;
    }
    if (pos < 1 || pos > L->length) {
        printf("插入位置错误");
        return 0;
    }
    for (int i = L->length - 1; i >= pos - 1; i--) {
        L->data[i + 1] = L->data[i];
    }
    L->data[pos - 1] = num;
    L->length++;
    return 1;
}

//删除失败返回0成功返回1.
int deleteElement(SeqList *L, int pos) {
    if (pos < 1 || pos > L->length) {
        printf("需要删除的数据位置错误\n");
        return 0;
    }
    if (L->length == 0) {
        printf("空表无法删除\n");
        return 0;
    }
    for (int i = pos - 1; i < L->length - 1; i++) {
        L->data[i]=L->data[i + 1];
    }
    L->length--;
    return 1;
}
//查找数据找到返回位置，未找到返回0.
int searchElement(SeqList *L, ElementType num) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == num) {
            return i+1;
        }
    }
    return 0;
}


    int main()
    {
        SeqList L;
        initList(&L);
        printf("初始化成功，目前长度为%d\n", L.length);
        printf("占用内存%zu字节\n", sizeof(L.data));
        appendElement(&L, 10);
        appendElement(&L, 20);
        appendElement(&L, 30);
        appendElement(&L, 40);
        showList(&L);
        insertElement(&L, 2, 22);
        showList(&L);
        deleteElement(&L, 2);
        showList(&L);
        return 0;
    }
