#include<stdio.h>
#include<stdlib.h>

int *list;
int length;
int max;

void init(int n)
{
	length = 0;
	max = n;
	list = (int *)malloc(max * sizeof(int));
}

int full()
{
	if(length == max)
		return 1;
	return 0;
}

int empty()
{
	if(length == 0)
		return 1;
	return 0;
}

int insert(int pos, int num)
{
	if(pos < 0 || pos > length || full())
	{
		printf("Error!\n\n");
		return 0;
	}
	for(int i = length - 1; i >= pos; i--)
		list[i + 1] = list[i];
	list[pos] = num;
	length++;
	return 1;
}

int quit(int pos)
{
	if(pos < 0 || pos >= length || empty())
	{
		printf("Error!\n\n");
		return 0;
	}
	printf("-->%d\n\n", list[pos]);
	for(int i = pos + 1; i < length; i++)
		list[i - 1] = list[i];
	length--;
	return 1;
}

int get(int pos)
{
	if(pos < 0 || pos >= length)
	{
		printf("Error!\n\n");
		return 0;
	}
	printf("num = %d\n\n", list[pos]);
	return 1;
}

int locate(int num)
{
	for(int i = 0; i < length; i++)
	{
		if(list[i] == num)
		{
			printf("pos = %d\n\n", i);
			return 1;
		}
	}
	printf("Error!\n\n");
	return 0;
}

void clear()
{
	length = 0;
}

void travel()
{
	for(int i = 0; i < length; i++)
		printf("%d\n", list[i]);
	printf("\n");
}

int main()
{
//	init(4);
//	insert(0, 1);
//	insert(1, 2);
//	insert(2, 3);
//	insert(3, 4);
//	insert(4, 5);
//	travel();
//	
//	get(0);
//	get(1);
//	get(2);
//	get(3);
//	
//	quit(0);
//	quit(2);
//	insert(2, 100);
//	insert(0, 200);
//	travel();
//	
//	get(0);
//	get(1);
//	get(2);
//	get(3);
//	
//	locate(100);
//	locate(1);
//	
//	clear();
//	travel();
	return 0;
}
