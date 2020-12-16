#include<stdio.h>
#define Maxsize 100

int Nnode;

typedef struct Arcnode{
    int adjVex;
    int weight;
    struct Arcnode *next;
}Arcnode;
Arcnode *AdjacencyList[Maxsize];

int root[Maxsize];
int Nroot;

int DFSnodevisited[Maxsize];
void DFSnodevisited0()
{
    for(int s = 0; s < Nnode; s++){
        DFSnodevisited[s] = 0;
    }
}
int DFS(int node)
{
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

int main(void)
{
    for(int i = 0; i < Nroot; i++){
        if(DFS(root[i])){
            printf("Have loop!\n");
            break;
        }
    };
    return 0;
}
