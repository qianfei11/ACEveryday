#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAX 100
#define ARR 20

typedef struct adjvert
{
    int adjvert;
    char flight_number[MAX];
    float price;
    float distance;
    char set_off_time[ARR];
    char arrive_time[ARR];
    struct adjvert *next;
}graph_adjvert;
typedef struct vert
{
    char city[128];
    graph_adjvert *head;
}graph_vert;
typedef struct
{
    graph_vert v[MAX];
    int n;
}graph;

void init_graph(graph *g)
{
    g->n = 0;
}

int create_vertex(graph *g, char *data)
{
    graph_vert *new_vert = &(g->v[g->n]);
    strcpy(new_vert->city, data);
    new_vert->head = NULL;
    g->n++;
    return g->n - 1;
}

void create_edge(graph *g, int v1, int v2, char flight_number[], float price, float distance, char *set_offtime, char *arrive_time)
{
    graph_adjvert *padjvert;
    padjvert = (graph_adjvert *)malloc(sizeof(graph_adjvert));
    padjvert->adjvert = v2;
    strcpy(padjvert->flight_number, flight_number);
    padjvert->price = price;
    padjvert->distance = distance;
    strcpy(padjvert->set_off_time, set_offtime);
    strcpy(padjvert->arrive_time, arrive_time);
    padjvert->next = g->v[v1].head;
    g->v[v1].head = padjvert;
}

int find_vertex(graph *g, char *data)
{
    for(int i = 0; i < g->n; i++)
        if(strcmp(g->v[i].city, data) == 0)
            return i;
    return -1;
}


int find_edge_1(graph *g, int v1, int v2)
{
    graph_adjvert *p = g->v[v1].head;
    while(p != NULL)
    {
        if(p->adjvert == v2)
            break;
        p = p->next;
    }
    printf(" --------------------------------------------------------------------------------------------------------- \n");
    printf("|   Departure   |    Arrival    | Flight Number |    Price    |   Distance   | Set-off Time | Arrive Time |\n");
    printf("| %13s | %13s | %13s | %11.1f | %12.1f | %12s | %11s |\n", g->v[v1].city, g->v[v2].city, p->flight_number, p->price, p->distance, p->set_off_time, p->arrive_time);
    printf(" --------------------------------------------------------------------------------------------------------- \n");
    return -1;
}

int find_edge_2(graph *g, char number[ARR])
{
    int i, j;
    graph_adjvert *p;
    for(int i = 0; i < g->n; i++)
    {
        p = g->v[i].head;
        j = -1;
        while(p != NULL)
        {
            if(strcmp(p->flight_number, number) == 0)
            {
                j = p->adjvert;
                break;
            }
            p = p->next;
        }
        if(j != -1)
            break;
    }
    printf(" --------------------------------------------------------------------------------------------------------- \n");
    printf("|   Departure   |    Arrival    | Flight Number |    Price    |   Distance   | Set-off Time | Arrive Time |\n");
    printf("| %13s | %13s | %13s | %11.1f | %12.1f | %12s | %11s |\n", g->v[i].city, g->v[j].city, p->flight_number, p->price, p->distance, p->set_off_time, p->arrive_time);
    printf(" --------------------------------------------------------------------------------------------------------- \n");
    return -1;
}

int main()
{
    graph a;
    init_graph(&a);
    while(1)
    {
        printf("Welcome to Flight System!\n");
        printf("1.Add info 2.Search info 3.Quit\n");
        int x;
        scanf("%d", &x);
        switch(x)
        {
            case 1:
            {
                printf("Please input the departure and the arrival:\n");
                char city1[ARR], city2[ARR];
                scanf("%s%s", city1, city2);
                int i, j;
                if((i = find_vertex(&a, city1)) == -1)
                    i = create_vertex(&a, city1);
                if((j = find_vertex(&a, city2)) == -1)
                    j = create_vertex(&a, city2);
                char flight_number[ARR];
                printf("Please input the flight number:\n");
                scanf("%s", flight_number);
                float price;
                printf("Please input the price:\n");
                scanf("%f", &price);
                float distance;
                printf("Please input the distance between two places:\n");
                scanf("%f", &distance);
                char set_offtime[ARR], arrive_time[ARR];
                printf("Please input the set-off time and the arrive time:\n");
                scanf("%s%s", set_offtime, arrive_time);
                create_edge(&a, i, j, flight_number, price, distance, set_offtime, arrive_time);
                break;
            }
            case 2:
            {
                printf("Please choose a way to search:\n");
                printf("1.Departure and Arrival 2.Flight number\n");
                int y;
                scanf("%d", &y);
                switch(y)
                {
                    case 1:
                    {
                        printf("Please input the departure and the arrival:\n");
                        char city1[ARR], city2[ARR];
                        scanf("%s%s", city1, city2);
                        int i = find_vertex(&a, city1), j = find_vertex(&a, city2);
                        find_edge_1(&a, i, j);
                        break;
                    }
                    case 2:
                    {
                        printf("Please input the flight number:\n");
                        char flight[ARR];
                        scanf("%s", flight);
                        find_edge_2(&a, flight);
                        break;
                    }
                    default:
                    {
                        printf("Input wrong!\n");
                        printf("Please input again!\n");
                    }
                }
                break;
            }
            case 3:
                return 0;
            default:
            {
                printf("Input wrong!\n");
                printf("Please input again!\n");
            }
        }
    }
}