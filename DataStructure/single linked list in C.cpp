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
			exit(0);
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

int length(plist head)//返回元素长度 
{
	plist p;
	int len = 0;
	for(p = head; p != NULL; p = p->next)
		len++;
	return len;
}

int locate(plist head, int num)//定位元素 
{
	plist p;
	int k = 0;
	for(p = head; p != NULL; p = p->next)
	{
		if(p->val == num)
		{
			printf("%d has been found at pos %d!\n\n", num, k);
			return 1;
		}
		k++;
	}
	printf("I can\'t found %d!\n\n", num);
	return 0;
}

int get(plist head, int pos)//查找元素              //pos从0开始 
{
	if(pos < 0 || pos >= length(head))
	{
		printf("Your pos is wrong!\n\n");
		return 0;
	}
	plist p = head;
	for(int i = 0; i < pos; i++)
		p = p->next;
	printf("Find %d at pos %d!\n\n", p->val, pos);
	return 1;
}

int del(plist head, int pos, int *x)//删除元素 
{
	if(pos < 0 || pos >= length(head))
	{
		printf("Your pos is wrong!\n\n");
		return 0;
	}
	plist p = head, pre = NULL;
	for(int i = 0; i < pos; i++)
	{
		pre = p;
		p = p->next;
	}
	pre->next = p->next;
	*x = p->val;
	free(p);
	printf("%d has been deleted at pos %d!\n\n", *x, pos);
	p = NULL;
	return 1;
}

int ins(plist head, int pos, int n)//前插元素 
{
	if(pos < 0 || pos > length(head))
	{
		printf("Your pos is wrong!\n\n");
		return 0;
	}
	plist p = head;
	for(int i = 0; i < pos - 1; i++)
		p = p->next;
	if(p == NULL)
	{
		printf("Error!\n\n");
		return 0;
	}
	plist tmp = (plist)malloc(sizeof(list));
	tmp->val = n;
	tmp->next = p->next;
	p->next = tmp;
	printf("Insert %d successfully before pos %d!\n\n", n, pos);
	return 1;
}

void inshead(plist head, int n)//在表头插入元素 
{
	plist p = head->next;
	plist tmp = (plist)malloc(sizeof(list));
	tmp->val = n;
	head->next = tmp;
	tmp->next = p;
	printf("Insert %d after the head successfully!\n\n", n);
}

void instail(plist head, int n)//在表尾插入元素 
{
	plist p = head;
	while(p->next != NULL)
		p = p->next;
	plist tmp = (plist)malloc(sizeof(list));
	tmp->val = n;
	p->next = tmp;
	tmp->next = NULL;
	printf("Insert %d after the tail successfully\n\n", n);
}

plist inverse(plist head)//单链表的逆序
{
	plist t, q, p;
	q = t = NULL;
	p = head;
	while(p != NULL)
	{
		t = p;
		p = p->next;
		t->next = q;
		q = t;
	}
	printf("Inverse the list successfully!\n\n");
	return t;
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
	head->val = 0;
	printf("Kill the list successfully!\n\n");
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

int main()
{
	plist head;
	head = create();
	printf("length = %d\n\n", length(head));
	print(head);
	
	locate(head, 1);
	locate(head, 100);
	get(head, 2);
	get(head, 10);
	
	ins(head, 4, 100);
	printf("length = %d\n\n", length(head));
	print(head);
	
	ins(head, 1, 66);
	printf("length = %d\n\n", length(head));
	print(head);
	
	inshead(head, 30);
	printf("length = %d\n\n", length(head));
	print(head);
	
	instail(head, 20);
	printf("length = %d\n\n", length(head));
	print(head);
	
	int *x;
	del(head, 2, x);
	del(head, 10, x);
	printf("length = %d\n\n", length(head));
	print(head);
		
	head = inverse(head);
	print(head);

	destroy(head);
	printf("length = %d\n\n", length(head));
	print(head);
	return 0;
}
