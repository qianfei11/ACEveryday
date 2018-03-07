#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}list, *plist;

plist create()//建立链表 
{
	plist head, tail, p;
	int n, num;
	head = tail = NULL;
	scanf("%d", &n);//要输入的数据个数 
	while(n--)
	{
		scanf("%d", &num);
		p = (plist)malloc(sizeof(list));
		if(p == NULL)
		{
			printf("Memory allocation failed!\n");
			exit(1);
		}
		p->val = num;
		p->next = NULL;
		if(head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	return head;
}

void print(plist head)//遍历链表 
{
	plist p = head;
	while(p)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

void bubblesort(plist head)//单链表的冒泡排序 
{
	plist pp, p, q, last;
	last = head;
	while(last->next != NULL)
		last = last->next;
	while(last != head->next)
	{
		pp = head;
		p = pp->next;
		while(p != last)
		{
			q = p->next;
			if(p->val > q->val)
			{
				pp->next = q;
				p->next = q->next;
				q->next = p;
				if(last == q)
					last = p;
			}
			pp = (p->val < q->val) ? p : q;
			p = pp->next;
		}
		last = pp;
	}
}

void destroy(plist head)//销毁链表 
{
	plist p = head->next, tmp;
	head->next = NULL;
	while(p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
}

int main()
{
	plist head;
	head = create();
	bubblesort(head);
	print(head);
	destroy(head); 
	return 0;
}
