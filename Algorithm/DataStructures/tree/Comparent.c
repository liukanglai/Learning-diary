#include<stdio.h>
#include<stdlib.h>

//定义树节点的结构体
typedef struct Tnode
{
    struct Tnode *lnode;
    struct Tnode *rnode;
    char value;
}Tnode;

Tnode* root=NULL;
char ch;

//创建二叉树
void creatTree(Tnode **p) 
{
    ch = getchar();
    if(ch =='#'){
        *p = NULL;
        return ;
    }
    *p = (Tnode*)malloc(sizeof(Tnode));
    (*p)->value = ch;
    creatTree(&((*p)->lnode));
    creatTree(&((*p)->rnode));
    return ;
}

Tnode* queue[100];
int Startqueue = 0;
int Stopqueue = 0;

void inqueue(Tnode* a)
{
    queue[Startqueue++] = a;
}

Tnode* outqueue()
{
    return queue[Stopqueue++];
}

void displayTree(Tnode** p)
{
    if(*p == NULL) return ;

    inqueue(*p);
    while(Stopqueue != Startqueue){
        Tnode *node = outqueue();
        if(node->lnode != NULL) inqueue(node->lnode);
        if(node->rnode != NULL) inqueue(node->rnode);
        putchar(node->value);
        putchar(' ');
    }
}

//销毁二叉树，回收分配的内存单元
void destroyTree(Tnode** p)
{
    if((*p) == NULL) return;
    destroyTree(&((*p)->lnode));
    destroyTree(&((*p)->rnode));
    free(*p);
}

int main(){

   creatTree(&root);
   displayTree(&root);
   destroyTree(&root);
   getchar();
   return 0;
}
