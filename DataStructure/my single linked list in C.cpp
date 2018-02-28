#include<stdio.h>
#include<stdlib.h>
//#define TEST

typedef struct member
{
	int val;
	struct member *next;
}list, *plist;

plist create()
{
	plist head, p, q;
	int n;
	head = p = (plist)malloc(sizeof(list));
	while(scanf("%d", &n), n)
	{
		p->val = n;
		q = p;
		p = (plist)malloc(sizeof(list));
		q->next = p;
	}
//	scanf("%d", &p->val);
//	while(p->val)
//	{
//		q = p;
//		p = (plist)malloc(sizeof(list));
//		scanf("%d", &p->val);
//		q->next = p;
//	}
	free(p);
	q->next = NULL;
	printf("Create a list successfully!\n\n");
	return head;
}

int length(plist head)
{
	plist p;
	int num = 0;
	for(p = head; p != NULL; p = p->next)
		num++;
	return num;
}

int locate(plist head, int num)
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

int get(plist head, int pos)
{
	if(pos < 0 || pos >= length(head))
	{
		printf("Your pos is wrong!\n\n");
		return 0;
	}
	plist p = head;
	for(int i = 0; i <= pos; i++)
		p = p->next;
	printf("Find %d at pos %d!\n\n", p->val, pos);
	return 1;
}

int quit(plist head, int pos)
{
	if(pos < 0 || pos >= length(head))
	{
		printf("Your pos is wrong!\n\n");
		return 0;
	}
	plist p = head, pre = NULL;
	pos = pos - 1;
	for(int i = 0; i <= pos; i++)
	{
		pre = p;
		p = p->next;
	}
	pre->next = p->next;
	int x = p->val;
	free(p);
	printf("%d has been deleted at pos %d!\n\n", x, pos + 1);
	p = NULL;
	return 1;
}

int insert(plist head, int pos, int n)
{
	if(pos < 0 || pos > length(head))
	{
		printf("Your pos is wrong!\n\n");
		return 0;
	}
	plist p = head;
	for(int i = 0; i < pos; i++)
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
	printf("Insert %d successfully after pos %d!\n\n", n, pos);
	return 1;
}

void inserthead(plist head, int n)
{
	plist p = head->next;
	plist tmp = (plist)malloc(sizeof(list));
	tmp->val = n;
	head->next = tmp;
	tmp->next = p;
	printf("Insert %d after head successfully!\n\n", n);
}

void inserttail(plist head, int n)
{
	plist p = head;
	while(p->next != NULL)
		p = p->next;
	plist tmp = (plist)malloc(sizeof(list));
	tmp->val = n;
	p->next = tmp;
	tmp->next = NULL;
	printf("Insert %d after tail successfully\n\n", n);
}

void destroy(plist head)
{
	plist p = head->next, tmp;
	head->next = NULL;
	while(p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	printf("Kill the list successfully!\n\n");
}

void print(plist head)
{
	plist p;
	for(p = head; p != NULL; p = p->next)
		printf("%d\n", p->val);
	printf("\n");
}

int main()
{
//	#ifdef TEST
//	freopen("D:\\in.txt", "r", stdin);
//	freopen("D:\\out.txt", "w", stdout);
//	#endif
//	
//	plist head;
//	head = create();
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	locate(head, 1);
//	locate(head, 100);
//	get(head, 2);
//	get(head, 10);
//	
//	insert(head, 4, 100);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	insert(head, 1, 66);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	inserthead(head, 30);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	inserttail(head, 20);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	quit(head, 2);
//	quit(head, 10);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	destroy(head);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
