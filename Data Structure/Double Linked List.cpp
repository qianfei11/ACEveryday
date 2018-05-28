#include<stdio.h>
#include<stdlib.h>

typedef struct doublelinked
{
	int val;
	struct doublelinked *pre;
	struct doublelinked *next;
}db, *pdb;
int size = 0;

pdb init()
{
	int n;
	pdb head, p, q;
	scanf("%d", &n);
	size = n;
	head = (pdb)malloc(sizeof(db));
	if(head == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(0);
	}
	head->val = 0;
	head->next = NULL;
	head->pre = NULL;
	q = head;
	for(int i = 0; i < n; i++)
	{
		p = (pdb)malloc(sizeof(db));
		if(p == NULL)
		{
			printf("Memory allocation failed!\n");
			exit(0);
		}
		scanf("%d", &p->val);
		q->next = p;
		p->pre = q;
		p->next = NULL;
		q = p;
	}
	head->pre = p;
	q->next = head;
	return head;
}

int insert(pdb head, int pos, int x)//前插 
{
	if(pos < 0 || pos > size)
	{
		printf("Your pos is wrong!\n");
		return 0;
	}
	pdb t = head;
	for(int i = 0; i < pos; i++)
		t = t->next;
	pdb p = (pdb)malloc(sizeof(db));
	p->val = x;
	p->pre = t->pre;
	p->next = t;
	t->pre->next = p;//原来t之前的节点的后驱指向p（与下一步不可调换顺序） 
	t->pre = p;//使t的前驱指向p（与上一步不可调换顺序） 
	printf("Successful insert %d at pos %d!\n", x, pos);
	size++;
	return 1;
}

int del(pdb head, int pos, int *x)
{
	if(pos < 0 || pos > size)
	{
		printf("Your pos is wrong!\n");
		return 0;
	}
	pdb p = head;
	for(int i = 0; i < pos; i++)
		p = p->next;
	p->pre->next = p->next;
	p->next->pre = p->pre;
	printf("%d has been deleted at pos %d successfully!\n", p->val, pos);
	free(p);
	size--;
	return 1;
}

void print(pdb head)
{
	pdb p;
	p = head->next;
	while(p != head)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

int main()
{
//	pdb head;
//	head = init();
//	print(head);
//	
//	int *x;
//	del(head, 3, x);
//	print(head);
//	
//	insert(head, 2, 100);
//	print(head);
	return 0;
}