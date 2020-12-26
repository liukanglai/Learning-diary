#include<stdio.h>


// Search

// 1. DFS深度优先搜索（depth-first search）
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
    if(DFSnodevisited[node]){
        return 0;
    }
    if(node == j) return 1; // ............... if i = j!!
    Arcnode *Tem = AdjacencyList[node]->next;
    while(Tem){
        if(Tem->adjVex == j) return 1; // more fast, if find j, no need to recursion 
        DFSnodevisited[node] = 1;
        if(DFS(Tem->adjVex)){
            return 1;
        }
        Tem = Tem->next;
    }
    return 0;
}

// recursion
void dfsRecursion(AdjListGraph* graph, int startVertexIndex, bool visit[])
{
    printf("%c ", (graph -> adjList[startVertexIndex]).info);
    visit[startVertexIndex] = true;
    EdgeNode* edgeIndex = (graph -> adjList[startVertexIndex]).firstEdge;
    while (edgeIndex != NULL)
    {
        if (visit[edgeIndex -> toAdjVex] == false)
            dfsRecursion(graph, edgeIndex -> toAdjVex, visit);
        edgeIndex = edgeIndex -> next;
    }
}

// stack
void dfsNonRecursion(AdjListGraph* graph, int startVertextIndex, bool visit[])
{
    linked_stack* stack = NULL;
    init_stack(&stack);

    // Visit the start vertex.
    printf("%c ", (graph -> adjList[startVertextIndex]).info);
    visit[startVertextIndex] = true;
    EdgeNode* edgeNode = (graph -> adjList[startVertextIndex]).firstEdge;
    if (edgeNode != NULL)
        push(stack, edgeNode);
    while (!isEmptyStack(stack))
    {
        edgeNode = ((EdgeNode*)pop(stack)) -> next;
        while (edgeNode != NULL && !visit[edgeNode -> toAdjVex])
        {
            printf("%c ", (graph -> adjList[edgeNode -> toAdjVex]).info);
            visit[edgeNode -> toAdjVex] = true;
            push(stack, edgeNode);
            edgeNode = (graph -> adjList[edgeNode -> toAdjVex]).firstEdge;
        }
    }
}


// 2. BFS

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

void bfs(AdjListGraph* graph, int startVertexIndex, bool visit[])
{
    // Loop queue initialization.
    LoopQueue loopQ;
    loopQ.front = 0;
    loopQ.rear = 0;
    LoopQueue* loopQueue = &loopQ;
    enqueue(loopQueue, &(graph -> adjList[startVertexIndex]));
    printf("%c ", (graph -> adjList[startVertexIndex]).info);
    visit[startVertexIndex] = true;
    while (!isEmpty(loopQueue))
    {
        VertexNode* vertexNode = dequeue(loopQueue);
        EdgeNode* edgeNode = vertexNode -> firstEdge;
        while(edgeNode != NULL)
        {
            if (visit[edgeNode -> toAdjVex] == false)
            {
                printf("%c ", (graph -> adjList[edgeNode -> toAdjVex]).info);
                visit[edgeNode -> toAdjVex] = true;
                enqueue(loopQueue, &(graph -> adjList[edgeNode -> toAdjVex]));
            }
            edgeNode = edgeNode -> next;
        }
    }
}



