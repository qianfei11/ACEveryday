//dijkstra
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX 20
#define INF 65535

typedef struct graph
{
    char ver[MAX + 1];
    int edg[MAX][MAX];
}graph;

int arr[MAX][MAX] = {
        {0, 6, 3, 0, 0, 0},
        {6, 0, 2, 5, 0, 0},
        {3, 2, 0, 3, 4, 0},
        {0, 5, 3, 0, 2, 3},
        {0, 0, 4, 2, 0, 5},
        {0, 0, 0, 3, 5, 0}
};
char vertex[MAX] = "ABCDEF";

void creategraph(graph *g)
{
    int vertexnum;
    for(int i = 0; i < strlen(vertex); i++)
        g->ver[i] = vertex[i];
    vertexnum = strlen(g->ver);
    for(int i = 0; i < vertexnum; i++)
        for(int j = 0; j < vertexnum; j++)
            g->edg[i][j] = arr[i][j];
}

void printgraph(graph g)
{
    int vertexnum = strlen(g.ver);
    printf("The vex are:\n");
    for(int i = 0; i < vertexnum; i++)
        printf("%c ", g.ver[i]);
    printf("\n");
    printf("The edges are:\n");
    for(int i = 0; i < vertexnum; i++)
        for(int j = i; j < vertexnum; j++)
            if(g.edg[i][j] != 0)
                printf("%c %c %d\n", g.ver[i], g.ver[j], g.edg[i][j]);
    printf("The map is:\n");
    for(int i = 0; i < vertexnum; i++)
    {
        for(int j = 0; j < vertexnum; j++)
        {
            printf("%d ", g.edg[i][j]);
        }
        printf("\n");
    }
}

int calculatevertexnum(graph g)
{
    return strlen(g.ver);
}

void setvertexweight(graph *g)
{
    for(int i = 0; i < calculatevertexnum(*g); i++)
        for(int j = 0; j < calculatevertexnum(*g); j++)
            if(0 == g->edg[i][j])
                g->edg[i][j] = INF;
}

void dijkstra(graph g)
{
    int vertexnum = calculatevertexnum(g);
    int minx;
    int index = 0;
    int *used = (int *)malloc(sizeof(int) * vertexnum);
    int *distance = (int *)malloc(sizeof(int) * vertexnum);
    int *parent = (int *)malloc(sizeof(int) * vertexnum);
    int *last = (int *)malloc(sizeof(int) * vertexnum);
    setvertexweight(&g);
    for(int i = 0; i < vertexnum; i++)
    {
        used[i] = 0;
        distance[i] = g.edg[0][i];
        last[i] = 0;
    }
    used[0] = 1;
    parent[index++] = 0;
    printf("Distance:\n");
    for(int i = 0; i < vertexnum; i++)
        printf("%6c", g.ver[i]);
    printf("\n");
    for(int i = 0; i < vertexnum - 1; i++)
    {
        for(int i = 0; i < vertexnum; i++)
            printf("%6d", distance[i]);
        printf("\n");
        int j = 0;
        minx = INF;
        for(int k = 0; k < vertexnum; k++)
        {
            if((0 == used[k]) && (distance[k] < minx))
            {
//                printf("%d is smaller than %d.\n", distance[k], minx);
                minx = distance[k];
                j = k;
            }
        }
//        printf("Find min: %d.\n", minx);
        used[j] = 1;
        for(int k = 0; k < vertexnum; k++)
        {
            if((0 == used[k]) && (distance[k] > distance[j] + g.edg[j][k]))
            {
//                printf("%d is replaced by %d.\n", distance[k], distance[j] + g.edg[j][k]);
                distance[k] = distance[j] + g.edg[j][k];
            }
        }
        parent[index++] = j;
    }
//    for(int i = 0; i < vertexnum; i++)
//        printf("%6d", distance[i]);
//    printf("\n");
    printf("The shortest way from place %c to place %c:\n", g.ver[0], g.ver[vertexnum - 1]);
    for(int i = 0; i < index; i++)
        printf("%c ", g.ver[parent[i]]);
    printf("\n");
    printf("The shortest path\'s length: %d.\n", minx);
}

int main()
{
    graph g;
    creategraph(&g);
    printgraph(g);
    dijkstra(g);
    return 0;
}