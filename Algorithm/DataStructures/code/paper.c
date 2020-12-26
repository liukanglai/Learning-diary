/*

 先是输入图的问题，论文中采用了通过微软基础类库( Microsoft Foundation Classes, MFC)中已有的CTypedPtrArray数组类模板实现路网的存储，动态创建新元素，统计元素个数等功能的方法，这不是本文讨论的算法问题，予以忽略。
 下面算法采取经典的邻接矩阵的存储方式，简化问题，直达算法本身。

 本文讨论的问题可简化为：在给定图中，有起点和终点，给出K个必经点以及N的大小，求出起点到终点必须经过那K个节点的N条最短路径（K, N < 5).

原图有回路是没有问题的，问题在于求出的最短路径中可不可以存在回路

1. 找到经过k个节点的最短路径 

- 中间节点全排列？


2. 求n条最短路径

- 断开第一条路径，找子图，怎么断开，断几条边
- 在所有子图中找到所有最短路径，最短的一条即为原图第几条最短路径（why，算了）
- 再次断开，找路径，是上一次的最断路径断开吗


*/


#include<stdio.h>
#include<stdlib.h>
#define VERTEX_NUM 26

int K, N; // K, N < 5

typedef struct
{
    int number;
    //VERTEX_DATA_TYPE info;
}Vertex;

typedef struct
{
    int edges[VERTEX_NUM][VERTEX_NUM];        // The value of this two dimensional array is the weight of the edge.
    int vertextNum;                             // The number of vertex.
    int edgeNum;                                // The number of edge.
    Vertex vex[VERTEX_NUM];                     // To store vertex.
}MGraph;


const int MAXN = 10000;
const int INF = 10000;
int d[MAXN];//记录v0到各定点的最小路径
int use[MAXN];//记录各节点是否已求得最短路径，0表示未求得，1表示已求得
int p[MAXN];//记录v0到个顶点最小路径的中间节点

void dijkstra(MGraph* G, int startVertexIndex, int endVertexIndex)
{
    for(int i = 0; i < VERTEX_NUM; i++){
        use[i] = 0;
        p[i] = 0;
        d[i] = G->edges[0][i];
    }
    use[0] = 1;//由于v0-v0不存在，因此当v0已求得最短路径

    for(int i = 1; i < VERTEX_NUM; i++){
        int s, min = INF;// s为中间点,min为最小路径
        for(int j = 0; j < VERTEX_NUM; j++){ // 找到最短的路径
            if(!use[j] && d[j] < min){
                min = d[j];
                s = j;
            }
        }
        use[s] = 1; // 标记此点已过
        for(int w = 0; w < VERTEX_NUM; w++){ // 重新标记路径
            if(!use[w] && min + G->edges[s][w] < d[w]){
                d[w] = min + G->edges[s][w];
                p[w] = s;
            }
        }
    }
}
 

int main(void)
{    
    MGraph *G = (MGraph *)malloc(sizeof(MGraph));
    //初始化图
    for(int i = 0; i < VERTEX_NUM; i++){
        for(int j = 0; j < VERTEX_NUM; j++){
            scanf("%d", G->edges[i][j]);
        }
    }
    return 0;
}
