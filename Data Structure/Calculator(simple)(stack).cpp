#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct
{
	char st[MAX];
	int top;
}stack, *pstack;

typedef struct
{
	int st[MAX];
	int top;
}nstack, *pnstack;

int prior(char n)
{
	if(n == '(')
		return 0;
	if(n == '+' || n == '-')
		return 1;
	if(n == '*' || n == '/')
		return 2;
	return 0;
}

int isnum(char n)
{
	if(n >= '0' && n <= '9')
		return 1;
	return 0;
}

void clear(pstack s)
{
	s->top = 0;
}

void nclear(pnstack s)
{
	s->top = 0;
}

int empty(pstack s)
{
	if(s->top == 0)
		return 1;
	return 0;
}

int full(pstack s)
{
	if(s->top >= MAX)
		return 1;
	return 0;
}

int nempty(pnstack s)
{
	if(s->top == 0)
		return 1;
	return 0;
}

int nfull(pnstack s)
{
	if(s->top >= MAX)
		return 1;
	return 0;
}

int push(pstack s, char n)
{
	if(full(s))
	{
		printf("Stack overflow!\n");
		return 0;
	}
	s->st[s->top++] = n;
	return 1;
}

int npush(pnstack s, char n)
{
	if(nfull(s))
	{
		printf("Stack overflow!\n");
		return 0;
	}
	s->st[s->top++] = n - '0';
	return 1;
}

char pop(pstack s)
{
	if(empty(s))
	{
		printf("Stack underflow!\n");
		return 0;
	}
	return s->st[--s->top];
}

int npop(pnstack s)
{
	if(nempty(s))
	{
		printf("Stack underflow!\n");
		return 0;
	}
	return s->st[--s->top];
}

char top(pstack s)
{
	if(empty(s))
	{
		printf("Stack is empty!\n");
		return 0;
	}
	return s->st[s->top - 1];
}

int ntop(pnstack s)
{
	if(nempty(s))
	{
		printf("Stack is empty!\n");
		return 0;
	}
	return s->st[s->top - 1];
}

void print(pstack s)
{
	for(int i = 0; i < s->top; i++)
		printf("%c", s->st[i]);
	printf("\n");
}

int main()
{
	pstack slave = (pstack)malloc(sizeof(stack));
	pnstack nst = (pnstack)malloc(sizeof(nstack));
	clear(slave);
	nclear(nst);
	char n;
	char infix[MAX], postfix[MAX];
	printf("This calculator can only do some easy operations, float or double is not valuable.\n");
	printf("Please input an infix(Your parentheses must be DBC case):\n");
	scanf("%s", infix);
	int len = strlen(infix), k = 0;
	for(int i = 0; i < len; i++)
	{
		if(isnum(infix[i]))
			postfix[k++] = infix[i];
		else if(infix[i] == ' ')
			continue;
		else
		{
			if(infix[i] == '(' || empty(slave))
			{
				push(slave, infix[i]);
				continue;
			}
			else if(infix[i] == ')')
			{
				while(top(slave) != '(')
				{
					postfix[k++] = top(slave);
					pop(slave);
				}
				pop(slave);
				continue;
			}
			while(!empty(slave) && top(slave) != '(' && prior(infix[i]) <= prior(top(slave)))
			{
				postfix[k++] = top(slave);
				pop(slave);
			}
			push(slave, infix[i]);
		}
	}
	while(!empty(slave))
	{
		postfix[k++] = top(slave);
		pop(slave);
	}
//	for(int i = 0; i < k; i++)//后缀表达式输出 
//		printf("%c", postfix[i]);
//	printf("\n");
	int x, y;
	for(int i = 0; i < k; i++)
	{
		if(isnum(postfix[i]))
			npush(nst, postfix[i]);
		else if(postfix[i] == '+')
			nst->st[nst->top - 1] += npop(nst);
		else if(postfix[i] == '-')
			nst->st[nst->top - 1] -= npop(nst);
		else if(postfix[i] == '*')
			nst->st[nst->top - 1] *= npop(nst);
		else if(postfix[i] == '/')
			nst->st[nst->top - 1] /= npop(nst);
	}
	printf("%d\n", npop(nst));
	return 0;
}