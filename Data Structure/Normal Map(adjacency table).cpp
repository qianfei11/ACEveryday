#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXVERTEXNUM 100

typedef struct adjvert // 邻接顶点数据类型
{
    int adjvert; // 邻接顶点索引号
    float edgeinfo; // 边上的数据信息
    struct adjvert *next;
}graph_adjvert;
typedef struct vert // 顶点数据类型
{
    char data[128]; //顶点数据
    graph_adjvert *phead; // 该顶点的邻接表表头指针
}graph_vert;
typedef struct // 图数据类型
{
    graph_vert v[MAXVERTEXNUM]; //顶点数组
    int n;
}graph;

void init_graph(graph *g)
{
    g->n = 0;
}

int create_vertex(graph *g, char *vertdata)
{
    graph_vert *pnewvert = &(g->v[g->n]);
    strcpy(pnewvert->data, vertdata);
    pnewvert->phead = NULL;
    g->n++;
    return g->n - 1;
}

void create_edge(graph *g, int v1, int v2, float edgedata)
{
    if(v1 < 0 || v1 >= g->n || v2 < 0 || v2 >= g->n)
    {
        printf("Your pos is illegal!\n");
        return;
    }
    graph_adjvert *padjvert;
    padjvert = (graph_adjvert *)malloc(sizeof(graph_adjvert));
    if(padjvert == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    padjvert->adjvert = v2;
    padjvert->edgeinfo = edgedata;
    padjvert->next = g->v[v1].phead;
    g->v[v1].phead = padjvert;
}

int delete_edge(graph *g, int v1, int v2)
{
    if(v1 < 0 || v1 >= g->n || v2 < 0 || v2 >= g->n)
    {
        printf("Your pos is illegal!\n");
        return 0;
    }
    graph_adjvert *tmp;
    tmp = g->v[v1].phead;
    g->v[v1].phead = NULL;
    free(tmp);
    return 1;
}

int find_vertex(graph *g, char *vertdata)
{
    for(int i = 0; i < g->n; i++)
    {
        if(strcmp(vertdata, g->v[i].data) == 0)
        {
            printf("Find %s at pos %d.\n", vertdata, i + 1);
            return 1;
        }
    }
    printf("Can\'t find %s.\n", vertdata);
    return 0;
}

graph_adjvert* find_edge(graph *g, int v1, int v2)
{
    graph_adjvert *tmp;
    tmp = g->v[v1].phead;
    while(tmp != NULL)
    {
        if(tmp->adjvert == v2)
        {
            printf("Find the edge between %s and %s!\n", g->v[v1].data, g->v[v2].data);
            printf("The edge\'s value is %.2f.\n", g->v[v1].phead->edgeinfo);
            return g->v[v1].phead;
        }
        tmp = tmp->next;
    }
    printf("Can\'t find the edge!\n");
    return NULL;
}

void print(graph *g)
{
    graph_adjvert *p;
    for(int i = 0; i < g->n; i++)
    {
        p = g->v[i].phead;
        while(p != NULL)
        {
            printf("%s %s %.2f\n", g->v[i].data, g->v[p->adjvert].data, p->edgeinfo);
            p = p->next;
        }
    }
}

int main()
{
    graph a;
    init_graph(&a);
    char str[128];
    int num;
    printf("Please input the sum of places you want to input:\n");
    scanf("%d", &num);
    printf("Please input the names of the places:\n");
    for(int i = 0; i < num; i++)
    {
        scanf("%s", str);
        int t = create_vertex(&a, str);
        printf("%s is at pos %d.\n", str, t);
    }
//    for(int i = 0; i < num; i++)
//        printf("%s\n", a.v[i].data);
    int m, n;
    float dis;
    printf("Please input the sum of the edges you want to input:\n");
    scanf("%d", &num);
    printf("Please input two places and the distanse:\n");
    for(int i = 0; i < num; i++)
    {
        scanf("%d %d %f", &m, &n, &dis);
        create_edge(&a, m, n, dis);
    }
//    printf("%d\n", num);
    print(&a);
    printf("Please input the edge you want to delete:\n");
    scanf("%d%d", &m, &n);
    delete_edge(&a, m, n);
    num--;
    print(&a);
    printf("Please input the place you want to find:\n");
    scanf("%s", str);
    find_vertex(&a, str);
    printf("Please input the edge you want to find:\n");
    scanf("%d%d", &m, &n);
    find_edge(&a, m, n);
    return 0;
}