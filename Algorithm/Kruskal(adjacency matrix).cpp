//Kruskal
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAX 4
#define MAXARR 25

typedef struct eg
{
    int start;
    int end;
    int weight;
}edge;

int addnum = 0;
edge arr[MAXARR];

int cmp(const void *v1,const void *v2)
{
    edge t1 = *(eg*)v1;
    edge t2 = *(eg*)v2;
    return t1.weight - t2.weight;
}

int main()
{
    int index = 0;
    char str[MAX + 1] = "ABCD";
    printf("The vex are:\n");
    for(int i = 0; i < strlen(str); i++)
        printf("%c ", str[i]);
    printf("\n");
    int a[MAX][MAX] = {{0, 4, 9, 8},
                       {4, 0, 21, 17},
                       {9, 21, 0, 16},
                       {8, 17, 16, 0}};
    printf("The map is:\n");
    for(int i = 1; i <= MAX; i++)
    {
        for(int j = 1; j <= MAX; j++)
        {
            printf("%4d", a[i - 1][j - 1]);
            if(j <= i)
                continue;
            else
            {
                arr[index].weight = a[i - 1][j - 1];
                arr[index].start = i;
                arr[index].end = j;
                index++;
            }
        }
        printf("\n");
    }
    printf("The edges are:\n");
    int num = MAX * (MAX - 1) / 2;
    qsort(arr, num, sizeof(edge), cmp);
    for(int i = 0; i < num; i++)
        printf("%c %c %d\n", str[arr[i].start - 1], str[arr[i].end - 1], arr[i].weight);
    int count = 0;
    int x[101];
    for(int i = 1; i <= 100; i++)
        x[i] = i;
    for(int i = 0; i < num && addnum < MAX; i++)
    {
//        for(int j = 0; j < MAX; j++)
//            printf("%d ", x[j]);
//        printf("\n");
        int k = arr[i].start, g = arr[i].end;
        while(k != x[k])
            k = x[k];
        while(g != x[g])
            g = x[g];
        if(k != g)  //如果线段的两个端点所在的集合不一样，说明加入该边不会构成回路
        {
            printf("Add %c and %c.\n", str[k - 1], str[g - 1]);
            x[g] = k;
            count += arr[i].weight;
            addnum++;
        }
    }
    printf("The smallest is %d.\n", count);
    return 0;
}