#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LEN 10
#define ROWS 6
#define COLS 7

typedef struct triple
{
    int r, c, e;
}datatype;

typedef struct m
{
    datatype num[LEN * LEN];
    int sum_r, sum_c, sum_e;
}matrix;

void shellsort(int num[], int len)          //希尔排序
{
    int tmp, x;
    for(int d = len / 2; d >= 1; d /= 2)
    {
        for(int i = d; i < len; i++)
        {
            for(tmp = num[i], x = i; x >= d && tmp < num[x - d]; x -= d)
            {
                num[x] = num[x - d];
            }
            num[x] = tmp;
        }
    }
}

void bubblesort(int num[], int len)        //冒泡排序
{
    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < len - i; j++)
        {
            if(num[j] > num[j + 1])
            {
                int tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }
}

void quicksort(int num[], int left, int right)       //快速排序
{
    if(left < right)
    {
        int i = left, j = right + 1;
        int standard = num[left];
        do
        {
            do
                i++;
            while(num[i] < standard);
            do
                j--;
            while(num[j] > standard);
            if(i < j)
            {
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }while(i < j);
        int tmp = num[left];
        num[left] = num[j];
        num[j] = tmp;
        quicksort(num, left, j - 1);
        quicksort(num, j + 1, right);
    }
}

void fasttranspose(matrix *a, matrix *b)      //矩阵快速转置
{
    int row_sum[COLS], starting_pos[COLS];
    b->sum_c = a->sum_r;
    b->sum_r = a->sum_c;
    b->sum_e = a->sum_e;
    memset(row_sum, 0, sizeof(row_sum));
    for(int i = 0; i < a->sum_e; i++)
        row_sum[a->num[i].c - 1]++;
    starting_pos[0] = 0;
    for(int i = 1; i < a->sum_c; i++)
        starting_pos[i] = starting_pos[i - 1] + row_sum[i - 1];
    for(int i = 0; i < a->sum_e; i++)
    {
        b->num[starting_pos[a->num[i].c - 1]].r = a->num[i].c;
        b->num[starting_pos[a->num[i].c - 1]].c = a->num[i].r;
        b->num[starting_pos[a->num[i].c - 1]].e = a->num[i].e;
        starting_pos[a->num[i].c - 1]++;
    }
}

int get(matrix m, int r, int c)
{
    for(int i = 0; i < m.sum_e; i++)
        if(m.num[i].r == r && m.num[i].c == c)
            return m.num[i].e;
    return 0;
}

void printmatrix(matrix m)
{
    for(int i = 1; i <= m.sum_r; i++)
    {
        for(int j = 1; j <= m.sum_c; j++)
        {
            printf("%3d", get(m, i, j));
        }
        printf("\n");
    }
}

int compare(int a, int b)
{
    if(a > b)
        return 1;
    else if(a == b)
        return 0;
    else
        return -1;
}

int binsearch(int num[], int searchnum, int left, int right)      //折半查找
{
    int middle;
    if(left <= right)
    {
        middle = (left + right) / 2;
        int sign = compare(num[middle], searchnum);
        switch(sign)
        {
            case 1:
                return binsearch(num, searchnum, left, middle - 1);
            case 0:
                return middle;
            case -1:
                return binsearch(num, searchnum, middle + 1, right);
        }
    }
    return 0;
}

void evalustion(int test[], int num[], int len)
{
    for(int i = 0; i < len; i++)
        test[i] = num[i];
}

int main()
{
    printf("List:\n");
    int num[LEN] = {89, 123, 32, 4, 65, 7, 66, 23, 39, 30};
    int test[LEN];
    printf("Init:\n");
    evalustion(test, num, LEN);
    for(int i = 0; i < LEN; i++)
        printf("%d ", test[i]);
    printf("\n");
    quicksort(test, 0, LEN - 1);
    printf("After quicksort:\n");
    for(int i = 0; i < LEN; i++)
        printf("%d ", test[i]);
    printf("\n");
    printf("Init:\n");
    evalustion(test, num, LEN);
    for(int i = 0; i < LEN; i++)
        printf("%d ", test[i]);
    printf("\n");
    shellsort(test, LEN);
    printf("After shellsort:\n");
    for(int i = 0; i < LEN; i++)
        printf("%d ", test[i]);
    printf("\n");
    printf("Init:\n");
    evalustion(test, num, LEN);
    for(int i = 0; i < LEN; i++)
        printf("%d ", test[i]);
    printf("\n");
    bubblesort(test, LEN);
    printf("After bubblesort:\n");
    for(int i = 0; i < LEN; i++)
        printf("%d ", test[i]);
    printf("\n");
    int n;
    printf("Please input the number u want 2 search:\n");
    scanf("%d", &n);
    int pos = binsearch(test, n, 0, LEN - 1);
    if(pos)
        printf("Find %d at pos %d.\n", n, pos + 1);
    else
        printf("Can\'t find %d.\n", n);
    printf("Matrix:\n");
    matrix n1, n2;
    int mat[ROWS][COLS] = {
            {0, 2, 0, 0, 0, 0, 0},
            {0, 0, 5, 0, 0, 0, 0},
            {8, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 9, 0},
            {0, 0, 0, 7, 0, 0, 0},
            {4, 0, 0, 0, 0, 0, 0}
    };
    int sum = 0;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(mat[i][j] != 0)
            {
                n1.num[sum].r = i + 1;
                n1.num[sum].c = j + 1;
                n1.num[sum].e = mat[i][j];
                sum++;
            }
        }
    }
    n1.sum_r = ROWS;
    n1.sum_c = COLS;
    n1.sum_e = sum;
    printmatrix(n1);
    fasttranspose(&n1, &n2);
    printf("After transpose:\n");
    printmatrix(n2);
    return 0;
}