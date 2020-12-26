// https://segmentfault.com/a/1190000020073055


#include<stdio.h>

// Create Graph

// 1. AdjacencyList 邻接表适用于稀疏图（边的数量远远小于顶点的数量）

// simple by me...
typedef struct Arcnode{
    int adjVex;
    int weight;
    struct Arcnode *next;
}Arcnode;
Arcnode *AdjacencyList[Maxsize];

// standard!
typedef struct EdgeNode
{
    int toAdjVex;                               // The index of vertex array which this edge points to.
    float weight;                               // The edge weight.
    struct EdgeNode *next;                      // The next edge, note that it only means the next edge also links to the vertex which this edge links to.
} EdgeNode;

typedef struct VertexNode
{
    VERTEX_DATA_TYPE info;                      // The vertex info,.
    struct EdgeNode* firstEdge;                 // The first edge which the vertex points to.
} VertexNode;

typedef struct
{
    VertexNode adjList[VERTEX_NUM];             // Adjacency list, which stores the all vertexes of the graph.
    int vertextNum;                             // The number of vertex.
    int edgeNum;                                // The number of edge.
} AdjListGraph;

// 2. AdjacencyMatrix 邻接矩阵适用于稠密图（边的数量比较多），它的抽象描述如下： 上图是个无向无权图，仅用0、1来表示两个顶点是否相连，当然，通常做法是将边的权值来代替1，用一个十分大的数字（如∞）来代替0，表示不相连。

typedef struct
{
    int number;
    VERTEX_DATA_TYPE info;
}Vertex;

typedef struct
{
    float edges[VERTEX_NUM][VERTEX_NUM];        // The value of this two dimensional array is the weight of the edge.
    int vertextNum;                             // The number of vertex.
    int edgeNum;                                // The number of edge.
    Vertex vex[VERTEX_NUM];                     // To store vertex.
}MGraph;

// 3. OrthogonalList

// 4. AdjacencyMulti-list



