//Prim
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 4

int main()
{
    int tmp = 0;
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
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    int arr[MAX + 1][MAX + 1];
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= MAX; i++)
        for(int j = 1; j <= MAX; j++)
            arr[i][j] = a[i - 1][j - 1];
    printf("The edges are:\n");
    for(int i = 0; i < MAX; i++)
        for(int j = i; j < MAX; j++)
            if(arr[i + 1][j + 1] != 0)
                printf("%c %c %d\n", str[i], str[j], arr[i + 1][j + 1]);
    for(int j = 1; j <= MAX - 1; j++)
    {
        int minx = 100000000;
        int index = 0;
        for(int i = 1; i <= MAX; i++)//取最小值
        {
            if(arr[1][i] == 0)
                continue;
            if(arr[1][i] < minx)
            {
                minx = arr[1][i];
                index = i;
            }
        }
        printf("Add %d.\n", arr[1][index]);
        tmp += arr[1][index];
        for(int i = 1; i <= MAX; i++)//将每条已连接的节点与其相邻节点的边上的权值进行比较
            arr[1][i] = min(arr[1][i], arr[index][i]);
    }
    printf("The smallest is %d.\n", tmp);
    return 0;
}