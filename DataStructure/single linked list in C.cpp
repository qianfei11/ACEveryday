#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}list, *plist;

plist create()//�������� 
{
	plist head, tail, p;
	int n, num;
	head = tail = NULL;
	scanf("%d", &n);//Ҫ��������ݸ��� 
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

int length(plist head)//����Ԫ�س��� 
{
	plist p;
	int num = 0;
	for(p = head; p != NULL; p = p->next)
		num++;
	return num;
}

int locate(plist head, int num)//��λԪ�� 
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

int get(plist head, int pos)//����Ԫ�� 
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

int del(plist head, int pos)//ɾ��Ԫ�� 
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

int ins(plist head, int pos, int n)//����Ԫ�� 
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

void inshead(plist head, int n)//������ͷ������Ԫ�� 
{
	plist p = head->next;
	plist tmp = (plist)malloc(sizeof(list));
	tmp->val = n;
	head->next = tmp;
	tmp->next = p;
	printf("Insert %d after head successfully!\n\n", n);
}

void instail(plist head, int n)//������β������Ԫ�� 
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

plist inverse(plist head)//�����������
{
	plist mid, tail, lead;
	tail = mid = NULL;
	lead = head;
	while(lead)
	{
		mid = lead;
		lead = lead->next;
		mid->next = tail;
		tail = mid;
	}
	return mid;
}

void destroy(plist head)//�������� 
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

void print(plist head)//�������� 
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
//	plist head;
//	head = create();
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	head = inverse(head);
//	print(head);
//	
//	locate(head, 1);
//	locate(head, 100);
//	get(head, 2);
//	get(head, 10);
//	
//	ins(head, 4, 100);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	ins(head, 1, 66);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	inshead(head, 30);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	instail(head, 20);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	del(head, 2);
//	del(head, 10);
//	printf("length = %d\n\n", length(head));
//	print(head);
//	
//	destroy(head);
//	printf("length = %d\n\n", length(head));
//	print(head);
	return 0;
}
