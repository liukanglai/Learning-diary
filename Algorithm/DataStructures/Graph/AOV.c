



// 1. TopologicalSorting

#include<stdio.h>

// 拓扑排序（topological sort）

// 顶点表示活动的网（activity on vertex network）或AOV网，


对于拓扑排序问题，所需的操作主要有：
1）判断顶点是否有前驱；
2）删除顶点和关联于该顶点的所有边。

for(i=0;i<n;i++)
{
    if every vertex has a predecessor
    {
        fprintf(stderr,"Network has a cycle.\n");
        exit(1);
    }
    pick a vertex v that has no predecessors;
    output v;
    delete v and all edges leading out of v from the netwok;
}

// 声明
typedef struct node *node_pointer;
typedef struct node
{
    int vertex;
    node_pointer link;
};
typedef struct
{
    int count;
    node_pointer link;
}hdnodes;
hdnodes graph[MAX_VERTICES];

// 函数
void topsort(hdnodes graph[],int n)
{
    int i,j,k,top;
    node_pointer ptr;
    top=-1;
    for(i=0;i<n;i++)
    {
        if(!graph[i].count)
        {
            graph[i].count=top;
            top=i;
        }
    }
    for(i=0;i<n;i++)
    {
        if(top==-1)
        {
            fprintf(stderr,"\nNetwork has a cycle. Sort terminated.\n");
            exit(1);
        }
        else
        {
            j=top;
            top=graph[top].count;
            printf("v%d, ",j);
            for(ptr=graph[j].link;ptr;ptr=ptr->link)
            {
                k=ptr->vertex;
                graph[k].count--;
                if(!graph[k].count)
                {
                    graph[k].count=top;
                    top=k;
                }
            }
        }
    }
}
