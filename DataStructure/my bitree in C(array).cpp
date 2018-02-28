#include<stdio.h>
#include<stdlib.h>

int max;
int *tree;

void create(int n, int root)
{
	max = n;
	tree = (int *)malloc(max * sizeof(int));
	for(int i = 0; i < max; i++)
		tree[i] = 0;
	tree[0] = root;
}

int search(int pos)
{
	if(pos < 0 || pos >= max || tree[pos] == 0)
	{
		printf("Error!\n\n");
		return 0;
	}
	printf("node = %d\n\n", tree[pos]);
	return 1;
}

int add(int pos, int dir, int x)//×ó£ºdir = 0 ÓÒ£ºdir = 1
{
	if(pos < 0 || pos >= max || tree[pos] == 0)
	{
		printf("Error!\n\n");
		return 0;
	}
	if(dir == 0)
	{
		if(2 * pos + 1 > max || tree[2 * pos + 1] != 0)
		{
			printf("Error!\n\n");
			return 0;
		}
		tree[2 * pos + 1] = x;
	}
	if(dir == 1)
	{
		if(2 * pos + 2 > max || tree[2 * pos + 2] != 0)
		{
			printf("Error!\n\n");
			return 0;
		}
		tree[2 * pos + 2] = x;
	}
	return 1;
}

int quit(int pos)
{
	if(pos < 0 || pos >= max || tree[pos] == 0)
	{
		printf("Error!\n\n");
		return 0;
	}
	printf("-->%d\n\n", tree[pos]);
	tree[pos] = 0;
	return 1;
}

void travel()
{
	for(int i = 0; i < max; i++)
		printf("%d\n", tree[i]);
	printf("\n");
}

int main()
{
//	create(10, 3);
//	add(0, 0, 5);
//	add(0, 1, 8);
//	add(1, 0, 2);
//	add(1, 1, 6);
//	add(2, 0, 9);
//	add(2, 1, 7);
//	travel();
//	
//	search(2);
//	search(10);
//	
//	quit(6);
//	quit(9);
//	travel();
	return 0;
}
