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
int path[Maxsize], Lpath = 0;

int DFSnodevisited[Maxsize];
void DFSnodevisited0()
{
    for(int s = 0; s < Nnode; s++){
        DFSnodevisited[s] = 0;
    }
}
void path0()
{
    for(int s = 0; s < Nnode; s++){
        path[s] = -1;
    }
}
void FindPath(node)
{
    path[Lpath++] = node;
    if(i == j){
        printf("%d\n", i);
        return;
    } 
    Arcnode *Tem = AdjacencyList[node]->next;
    while(Tem){
        if(Tem->adjVex == j){
            for(int s = 0; s < Lpath; s++){
                printf("%d ", path[s]);
            }
            printf("%d", j);
            DFSnodevisited[node] = 0;
            return;
        }
        DFSnodevisited[node] = 1;
        FindPath(Tem->adjVex);
        path[--Lpath] = -1;
        Tem = Tem->next;
    }
    DFSnodevisited[node] = 0;
}
int main(void)
{
    scanf("%d %d", &i, &j);
    FindPath(i);
    return 0;
}
