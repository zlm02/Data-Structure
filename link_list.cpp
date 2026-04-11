#include <cstdlib>
#include<stdio.h>
typedef int ElementType;

typedef struct node{
    ElementType data;
    struct node *next;
}Node;

//初始化链表
Node* initList() {
   Node *head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->data=0;
    return head;
}
//头插法
void headinsert(Node* L,ElementType x) {
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=L->next;
    L->next=temp;
}
//找到尾部节点。
Node * get_tail(Node* L) {
    Node *p=L;
    while (p->next!=NULL) {
        p=p->next;
    }
    return p;
}
//尾插法
Node* tailinsert(Node* tail,ElementType x) {
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    tail->next=temp;
    temp->next=NULL;
    return temp;
}
//指定位置插入。失败返回0，成功1
int poseinsert(Node*L,int pose,ElementType x) {
    Node *p=L;
    int i=0;
    while (i<pose-1) {
        p=p->next;
        i++;
        if (p->next==NULL) {
            return 0;
        }
    }
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=x;
    q->next=p->next;
    p->next=q;
    return 1;
}
//删除节点。失败返回0，成功返回1.
int deleteNode(Node*L,int pose) {
    Node *p=L;
    int i=0;
    while (i<pose-1) {
        p=p->next;
        i++;
        if (p==NULL) {
            return 0;
        }
    }
    if (p->next==NULL) {
        return 0;
    }
    Node* q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}
//获取链表长度并且return返回,不包含头节点。
int lengthlist(Node* L) {
    int length=0;
    Node* p=L->next;
    while (p!=NULL) {
        p=p->next;
        length++;
    }
    return length;
}
//链表的释放。
void freelist(Node* L) {
    Node* p=L;
    Node *q;
    while(p!=NULL) {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;


}

//链表的遍历。
void showList(Node* L) {
    Node *p=L->next;
    while (p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}



int main() {
    Node *head=initList();
    headinsert(head,4);
    headinsert(head,3);
    headinsert(head,2);
    tailinsert((get_tail(head)),5);
    poseinsert(head,2,3);
    showList(head);
    printf("%d\n",lengthlist(head));
    deleteNode(head,1);
    showList(head);
}
