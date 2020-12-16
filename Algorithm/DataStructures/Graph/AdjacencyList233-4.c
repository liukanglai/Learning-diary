#include<stdio.h>
#define Maxsize 100

int Nnode;

typedef struct Arcnode{
    int adjVex;
    int weight;
    struct Arcnode *next;
}Arcnode;
Arcnode *AdjacencyList[Maxsize];

int i, j;

int DFSnodevisited[Maxsize];
void DFSnodevisited0()
{
    for(int s = 0; s < Nnode; s++){
        DFSnodevisited[s] = 0;
    }
}
int DFS(int node)
{
    if(node == j) return 1; // ............... if i = j!!
    Arcnode *Tem = AdjacencyList[node]->next;
    while(Tem){
        if(Tem->adjVex == j) return 1;
        DFSnodevisited[node] = 1;
        if(DFS(Tem->adjVex)){
            return 1;
        }
        Tem = Tem->next;
    }
    return 0;
}

int BFSnodevisited[Maxsize];
void BFSnodevisited0()
{
    for(int s = 0; s < Nnode; s++){
        BFSnodevisited[s] = 0;
    }
}
int BFSqueue[Maxsize];
int start = 0, end = 0;
void enBFSqueue(int node)
{
    BFSqueue[end++] = node;
}
int outBFSqueue()
{
    return BFSqueue[start++];
}
int BFS(int node)
{
    enBFSqueue(node);
    while(start < end){
        int k = outBFSqueue();
        if(AdjacencyList[k]->adjVex == j){
            return 1;
        }
        BFSnodevisited[k] = 1;
        Arcnode *Tem = AdjacencyList[k];
        while(Tem->next){
            if(Tem->next->adjVex == j) return 1; // can judge without this, but use it more efficiently.
            if(BFSnodevisited[Tem->next->adjVex]) enBFSqueue(Tem->next->adjVex);
            Tem = Tem->next;
        }
    }
    return 0;
}

int main(void)
{
    scanf("%d %d", &i, &j);
    DFSnodevisited0();
    if(DFS(i)){
        printf("Yes\n");
    }
    else{
        printf("NO\n");
    }

    DFSnodevisited0();
    if(BFS(i)){
        printf("Yes\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
