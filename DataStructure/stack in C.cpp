#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAXLEN 100
#define EMPTY_STACK_ERROR -999999

typedef struct s
{
	int elem[MAXLEN];
	int top;
}stack, *pstack;

void init_stack(pstack s)
{
	memset(s->elem, 0, sizeof(s->elem));
	s->top = 0;
}

int isempty(pstack s)
{
	if(s->top == 0)
		return 1;
	else
		return 0;
}

int isfull(pstack s)
{
	if(s->top == MAXLEN)
		return 1;
	else
		return 0;
}

int push(pstack s, int x)
{
	if(s->top == MAXLEN)
		return 0;
	s->elem[++s->top] = x;
	return 1;
}

int pop(pstack s)
{
	if(isempty(s))
	{
		cout << "can\'t pop data from empty stack!" << endl;
		return EMPTY_STACK_ERROR;
	}
	int x = s->elem[s->top];
	s->top--;
	return x;
}

int get_top(pstack s)
{
	return s->elem[s->top];
}

void clear(pstack s)
{
	s->top = 0;
}

void reverse_data(int num[])
{
	stack s;
	int e;
	init_stack(&s);
	for(int i = 0; i < 10; i++)
		push(&s, num[i]);
	while((e = pop(&s)) != EMPTY_STACK_ERROR)
		cout << e << endl;
}

void ConvertOCT(int n)
{
	stack s;
	int e;
	init_stack(&s);
	while(n != 0)
	{
		push(&s, n % 8);
		n /= 8;
	}
	while((e = pop(&s)) != EMPTY_STACK_ERROR)
		cout << e;
	cout << endl;
}

int main()
{
	stack s;
	int e;
	init_stack(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	while((e = pop(&s)) != EMPTY_STACK_ERROR)
		cout << e << endl;
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	reverse_data(a);
	cout << "Please input an integar:" << endl;
	cin >> e;
	cout << "The result of convert is:" << endl;
	ConvertOCT(e);
	return 0;
}