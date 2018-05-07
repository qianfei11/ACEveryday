#include<cstdio>
#include<cstdlib>

typedef struct
{
    int *elem;
    int row, col;
}intmatrix;

void initmatrix(intmatrix *m, int row, int col)
{
    m->row = row;
    m->col = col;
    m->elem = (int *)malloc(sizeof(int) * row * col);
}

int assign(intmatrix *m, int i, int j, int x)
{
    if((i < 1 || i > m->row) || (j < 1 || j > m->col))
    {
        printf("Your col or row is illegal!\n");
        return 0;
    }
    m->elem[m->col * (i - 1) + (j - 1)] = x;
    return 1;
}

int get(intmatrix *m, int i, int j, int &x)
{
    if((i < 1 || i > m->row) || (j < 1 || j > m->col))
    {
        printf("Your col or row is illegal!\n");
        return 0;
    }
    x = m->elem[m->col * (i - 1) + (j - 1)];
    return 1;
}

void printmatrix(intmatrix *m)
{
    for(int i = 1; i <= m->row; i++)
    {
        for(int j = 1; j <= m->col; j++)
        {
            printf("%d ", m->elem[m->col * (i - 1) + (j - 1)]);
        }
        printf("\n");
    }
}

int main()
{
    intmatrix a, b;
    int n;
    initmatrix(&a, 4, 5);
    initmatrix(&b, 5, 4);
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            scanf("%d", &n);
            assign(&a, i, j, n);
        }
    }
    printmatrix(&a);
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            get(&a, i, j, n);
            assign(&b, j, i, n);
        }
    }
    printmatrix(&b);
    return 0;
}