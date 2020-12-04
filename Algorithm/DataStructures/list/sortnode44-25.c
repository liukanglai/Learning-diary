#include<stdio.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void sort(node *L){
    //寻找中间结点, 双指针法
    node *p = L, *q = L;
    while(q->next){
        q = q->next;
        if(q->next){
            q = q->next;
            p = p->next;
        }
    }

    //将链表后半段逆置
    q = p->next;
    p->next = NULL;
    node *r;
    while(q){
        r = q->next;
        q->next = p->next;
        p->next = q;
        q=r;
    }
    q = p->next;
    r = p;  // record the front node of q;
    p = L;
    while(q){
        r->next = q->next;
        q->next = p->next;
        p->next = q;
        p = q->next;
        q = r->next;
    }
}

int main(void)
{
    node *head;

    sort(head);
    return 0;

}

