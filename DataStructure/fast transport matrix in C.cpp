#include<stdio.h>
#include<string.h>
#define MAX 101

typedef int elemtype;
typedef struct a{
	int row;
	int col;
	elemtype val;
}triple;
typedef struct b{
	triple data[MAX];
	int hang, lie, sum;
}matrix;

int fasttransport(matrix m, matrix &t)
{
	t.hang = m.lie;
	t.lie = m.hang;
	t.sum = m.sum;
	if(t.sum)
	{
		int q;
		int col = m.lie;
		int num[100], cpot[100];
		memset(num, 0, sizeof(num));
		for(int i = 1; i <= col; i++)
			num[m.data[i].col]++;
		cpot[1] = 1;
		for(int i = 2; i <= col; i++)
			cpot[i] = cpot[i - 1] + num[i - 1];
		for(int i = 1; i <= m.sum; i++)
		{
			col = m.data[i].col;
			q = cpot[col];
			t.data[q].row = m.data[i].col;
			t.data[q].col = m.data[i].row;
			t.data[q].val = m.data[i].val;
			cpot[col]++;
		}
	}
	return 1;
}

int main()
{
	matrix m, t;
	printf("Please input the matrix:\n");
	printf("The row:");
	scanf("%d", &m.hang);
	printf("The column:");
	scanf("%d", &m.lie);
	printf("The sum of numbers:");
	scanf("%d", &m.sum);
	for(int i = 1; i <= m.sum; i++)
		scanf("%d%d%d", &m.data[i].row, &m.data[i].col, &m.data[i].val);
	fasttransport(m, t);
	printf("The matrix after transport:\n");
	for(int i = 1; i <= t.sum; i++)
		printf("%d	%d	%d\n", t.data[i].row, t.data[i].col, t.data[i].val);
	return 0;
}
