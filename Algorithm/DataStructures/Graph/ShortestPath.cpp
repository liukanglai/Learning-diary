#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int VERTEX_NUM;
// 最短路径算法

//1. 单源最短路径算法——迪杰斯特拉算法（Dijkstra Algorithm）

const int MAXN = 10000;
const int INF = 10000;
int d[MAXN];//记录v0到各定点的最小路径
int use[MAXN];//记录各节点是否已求得最短路径，0表示未求得，1表示已求得
int p[MAXN];//记录v0到个顶点最小路径的中间节点

int G[MAXN][MAXN];//图的矩阵
int N;

int main(){
    int i,j;
    cin >> N;
    //初始化图
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            cin >> G[i][j];
        }
    }
    fill(use, use+N, 0);
    fill(p, p+N, 0);
    for(i = 0; i < N; i++){
        d[i] = G[0][i];
    }
    use[0] = 1;//由于v0-v0不存在，因此当v0已求得最短路径

    for(i = 1; i < N; i++){
        int k, min = INF;// k为中间点,min为最小路径
        for(j = 0; j < N; j++){ // 找到最短的路径
            if(!use[j] && d[j] < min){
                min = d[j];
                k = j;
            }
        }
        use[k] = 1; // 标记此点已过
        for(int w = 0; w < N; w++){ // 重新标记路径
            if(!use[w] && min + G[k][w] < d[w]){
                d[w] = min + G[k][w];
                p[w] = k;
            }
        }
    }
    //打印结果
    int t = p[N-1];
    cout << 5 << " << ";
    while(t > 0){
        cout << t << " << ";
        t = p[t];
    }
    cout << 0;
    cout << endl << d[N-1];
}

void dijkstra(MGraph* graph, int startVertexIndex)
{
    // For storing the minimum cost from the arbitrary node to the start vertex.
    float minCostToStart[VERTEX_NUM];
    // For marking whether the node is in the set.
    int set[VERTEX_NUM];
    // Initialization
    for(int i = 0; i < VERTEX_NUM; i++) {
        minCostToStart[i] = graph->edges[i][startVertexIndex];
        set[i] = 0;
    }
    // Add the start vertex into the set.
    set[startVertexIndex] = 1;
    int minNodeIndex = startVertexIndex;
    for (int count = 1; count < VERTEX_NUM; count++){
        int minCost = MAX_COST;
        // Find the adjacent node which is nearest to the startVertexIndex.
        for (int i = 0; i < VERTEX_NUM; i++) {
            if (!set[i] && minCostToStart[i] < minCost)
            {
                minCost = minCostToStart[minNodeIndex];
                minNodeIndex = i;
            }
        }
        // Add the proper node into the set
        set[minNodeIndex] = 1;
        // After the new node is added into the set, update the minimum cost of each node which is out of the set.
        for (int i = 0; i < VERTEX_NUM; i++) {
            if (!set[i] && (graph -> edges[i][minNodeIndex]) < MAX_COST) {
                // The new cost of each node to source = the cost of new added node to source + the cost of node i to new added node.
                float newCost = minCostToStart[minNodeIndex] + graph -> edges[i][minNodeIndex];
                if (newCost < minCostToStart[i])
                    minCostToStart[i] = newCost;
            }
        }
    }
    printf("The cost of %c to each node:\n", (graph -> vex[startVertexIndex]).info);
    for (int i = 0; i < VERTEX_NUM; i++) {
        if (i != startVertexIndex)
            printf("-----> %c : %f\n", (graph -> vex[i]).info, minCostToStart[i]);
    }
}


//2. 多源最短路径算法——弗洛伊德算法（Floyd Algorithm）

void floyd(MGraph* graph)
{
    float minCost[VERTEX_NUM][VERTEX_NUM];          // Store the distance between any two nodes.
    int path[VERTEX_NUM][VERTEX_NUM];               // Store the intermediate node between the two nodes.
    int i, j, k;

    // Initialization
    for (i = 0; i < VERTEX_NUM; i++)
    {
        for (j = 0; j < VERTEX_NUM; j++)
        {
            minCost[i][j] = graph -> edges[i][j];
            path[i][j] = -1;
        }
    }

    // Find if there is another k node, it makes the distance dis[i][k] + dis[k][j] < dis[i][j];
    for (k = 0; k < VERTEX_NUM; k++)
        for (i = 0; i < VERTEX_NUM; i++)
            for (j = 0; j < VERTEX_NUM; j++)
            {
                if (minCost[i][j] > minCost[i][k] + minCost[k][j])
                {
                    minCost[i][j] = minCost[i][k] + minCost[k][j];
                    path[i][j] = k;
                }
            }

    for (i = 0; i < VERTEX_NUM; i++)
        for (j = 0; j < VERTEX_NUM; j++)
        {
            if (i != j && minCost[i][j] != MAX_COST)
                printf("%c ---> %c, the minimum cost is %f\n", (graph -> vex[i]).info, (graph -> vex[j]).info, minCost[i][j]);
        }
}



