#include<cstdio>
#include<cstdlib>
#define MAXNUM 20
#define ROWS 6
#define COLS 7

typedef struct
{
    int r, c, e;
}triple;
typedef struct
{
    triple elem[MAXNUM];
    int nrow, ncol, num;
}sparsematrix;

void buildsparsematrix(int m[ROWS][COLS], sparsematrix *psm)
{
    int n = 0;
    for(int i = 0; i < ROWS; ++i)
        for(int j = 0; j < COLS; ++j)
        {
            if(m[i][j] != 0)
            {
                psm->elem[n].r = i+1;
                psm->elem[n].c = j+1;
                psm->elem[n].e = m[i][j];
                ++n;
            }
        }
    psm->nrow = ROWS;
    psm->ncol = COLS;
    psm->num = n;
}

int get(sparsematrix *psm, int r, int c)
{
    int i = 0;
    for( ; i < psm->num; i++)
        if(psm->elem[i].r == r && psm->elem[i].c == c)
            return psm->elem[i].e;
    return 0;
}

void printsmatrix(sparsematrix *psm)
{
    for(int i = 1; i <= psm->nrow; i++)
    {
        for(int j = 1; j <= psm->ncol; j++)
        {
            printf("%3d ", get(psm, i, j));
        }
        printf("\n");
    }
}

void translate3(sparsematrix *pmata, sparsematrix *pmatb)
{
    int row_terms[COLS], starting_pos[COLS];
    pmatb->ncol = pmata->nrow;
    pmatb->nrow = pmata->ncol;
    pmatb->num = pmata->num;
    for(int i = 0; i < COLS; i++)
        row_terms[i] = 0;
    for(int i = 0; i < pmata->num; i++)
        row_terms[ pmata->elem[i].c - 1]++;
    starting_pos[0]=0;
    for(int i = 1; i < pmata->ncol; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1] ;
    for(int i = 0; i < pmata->num; i++)
    {
        pmatb->elem[starting_pos[pmata->elem[i].c - 1]].r = pmata->elem[i].c ;
        pmatb->elem[starting_pos[pmata->elem[i].c - 1]].c = pmata->elem[i].r ;
        pmatb->elem[starting_pos[pmata->elem[i].c - 1]].e = pmata->elem[i].e ;
        starting_pos[pmata->elem[i].c - 1]++;
    }
}

void add(sparsematrix *pmata, sparsematrix *pmatb, sparsematrix *pmatc)
{
    int i = 0, j = 0, n = 0, sum;
    if(pmata->nrow != pmatb->nrow || pmata->ncol != pmatb->ncol)
    {
        printf("Error found!\n");
        return;
    }
    while(i < pmata->num && j < pmatb->num)
    {
        if(pmata->elem[i].r < pmatb->elem[j].r)
            pmatc->elem[n++] = pmata->elem[i++];
        else if(pmata->elem[i].r > pmatb->elem[j].r)
            pmatc->elem[n++] = pmatb->elem[j++];
        else
        {
            if(pmata->elem[i].c < pmatb->elem[j].c)
                pmatc->elem[n++] = pmata->elem[i++];
            else if(pmata->elem[i].c > pmatb->elem[j].c)
                pmatc->elem[n++] = pmatb->elem[j++];
            else
            {
                sum = pmata->elem[i].e + pmatb->elem[j].e;
                if(sum != 0)
                {
                    pmatc->elem[n].r = pmatb->elem[j].r;
                    pmatc->elem[n].c = pmatb->elem[j].c;
                    pmatc->elem[n++].e = sum;
                }
                i++;
                j++;
            }
        }
    }
    if(i < pmata->num)
        for( ; i < pmata->num; i++)
            pmatc->elem[n++] = pmata->elem[i];
    else if(j < pmatb->num)
        for( ; j < pmata->num; j++)
            pmatc->elem[n++] = pmatb->elem[j];
    pmatc->nrow = pmata->nrow;
    pmatc->ncol = pmata->ncol;
    pmatc->num = n;
}

void mul(sparsematrix *pmata, sparsematrix *pmatb, sparsematrix *pmatc)
{
    int sum;
    int rterm[COLS] = {0};
    int cterm[COLS] = {0};
    if(pmata->nrow != pmatb->ncol)
    {
        printf("Error found!\n");
        return;
    }
    pmatc->nrow = pmata->nrow;
    pmatc->ncol = pmatb->ncol;
    pmatc->num = 0;
    for(int i = 1; i <= pmata->nrow; i++)
    {
        for(int r = 0; r < pmata->ncol; r++)
            rterm[r] = 0;
        for(int j = 0; j < pmata->num; j++)
            if(pmata->elem[j].r == i)
                rterm[pmata->elem[j].c - 1] = pmata->elem[j].e;
        for(int j = 1; j <= pmatb->ncol; j++)
        {
            for(int c = 0; c < pmatb->nrow; c++)
                cterm[c] = 0;
            for(int c = 0; c < pmatb->num; c++)
                if(pmatb->elem[c].c == j)
                    cterm[pmatb->elem[c].r - 1] = pmatb->elem[c].e;
            sum = 0;
            for(int r = 0; r < pmata->ncol; r++)
                sum += rterm[r] * cterm[r];
            if(sum != 0)
            {
                pmatc->elem[pmatc->num].r = i;
                pmatc->elem[pmatc->num].c = j;
                pmatc->elem[pmatc->num++].e = sum;
            }

        }
    }
}

int main()
{
    int i,j,x,y;
    int a[ROWS][COLS] = {{0,2,0,0,0,0,0},
                         {0,0,5,0,0,0,0},
                         {8,0,0,0,0,0,0},
                         {0,0,0,0,0,10,0},
                         {0,0,0,7,0,0,0},
                         {4,0,0,0,0,0,0}};
    int b[ROWS][COLS] = {{0,-2,0,0,0,0,0},
                         {0,0,6,0,0,0,0},
                         {0,0,13,0,0,0,0},
                         {0,0,0,0,0,0,-7,},
                         {6,0,7,0,0,0,0},
                         {0,0,0,8,0,0,0}};
    sparsematrix smat1, smat2, smat3,smat4;
    buildsparsematrix(a, &smat1);
    buildsparsematrix(b, &smat2);
    printf("\n");
    printsmatrix(&smat1);
    printf("\n");
    printsmatrix(&smat2);
    add(&smat1, &smat2, &smat3);
    printf("\n");
    printsmatrix(&smat3);
    translate3(&smat3, &smat2);
    printf("\n");
    printsmatrix(&smat2);
    mul(&smat1, &smat2, &smat4);
    printf("\n");
    printsmatrix(&smat4);
    return 0;
}