#include<cstdio>
#include<cstdlib>
#define MAXLEN 16
#define DIM 4

typedef struct
{
    int elem[MAXLEN];
}intcompressedmatrix;

void initmatrix(intcompressedmatrix *m, int mat[DIM][DIM])
{
    int index = 0;
    for(int i = 1; i <= DIM; i++)
        for(int j = 1; j <= i; j++)
            m->elem[index++] = mat[i - 1][j - 1];
}

int get(intcompressedmatrix *m , int i , int j, int *x)
{
    if((i < 1 || i > DIM) || (j < 1 || j > DIM))
        return 0;
    if(i >= j)
        *x = m->elem[i * (i - 1) / 2 + (j - 1)];
    else
        *x = m->elem[j * (j - 1) / 2 + (i - 1)];
    return 1;
}

int main()
{
    int m1[DIM][DIM] = {
            10, 5, 3, 17,
            5, 7, 12, 4,
            3, 12, 20, 23,
            17, 4, 23, 14
    };
    intcompressedmatrix mat;
    initmatrix(&mat, m1);
    int x;
    for(int i = 1; i <= DIM; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            get(&mat, i, j, &x);
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}