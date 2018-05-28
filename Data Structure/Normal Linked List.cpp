#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}list, *plist;

plist initlist()
{
	plist head = (plist)malloc(sizeof(list));
	head->data = 0;
	head->next = NULL;
	return head;
}

int insertlist(plist head, int pos, int x)
{
	plist q = 0, p = head;
	int j = 0;
	while(p->next != NULL && j < pos - 1)
	{
		p = p->next;
		j++;
	}
	if(j != pos - 1)
	{
		cout << "Error!" << endl;
		return -1;
	}
	q = (plist)malloc(sizeof(list));
	q->data = x;
	q->next = p->next;
	p->next = q;
	return pos;
}

int getlist(plist head, int pos)
{
	int j;
	plist p = head;
	while(p != NULL && j < pos - 1)
	{
		p = p->next;
		j++;
	}
	if(p == NULL)
		exit(0);
	return p->data;
}

int deletelist(plist head, int pos)
{
	plist p = head, pre = NULL;
	for(int i = 0; i < pos; i++)
	{
		pre = p;
		p = p->next;
	}
	pre->next = p->next;
	int x = p->data;
	free(p);
	return x;
}

int findlist(plist head, int x)
{
	plist p;
	int flag = 0;
	for(p = head; p != NULL; p = p->next)
	{
		if(p->data == x)
			flag = 1;
	}
	if(flag == 1)
	{
		cout << "Find" << x << "!" << endl;
		return 1;
	}
	else
	{
		cout << "Can\'t find" << x << "!" << endl;
		return 0;
	}
}

int lengthlist(plist head)
{
	int len = 0;
	plist p;
	for(p = head; p->next != NULL; p = p->next)
		len++;
	return len;
}

void clearlist(plist head)
{
	cout << "Start clear the list!" << endl;
	plist p = head->next, tmp;
	head->next = NULL;
	while(p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}	
	head->data = 0;
	cout << "Finish clearing!" << endl;
}

void printlist(plist head)
{
	plist p;
	cout << endl;
	for(p = head; p != NULL; p = p->next)
		cout << p->data << endl;
	cout << endl;
}

plist inverselist(plist head)
{
	plist t, p, q;
	q = t = NULL;
	p = head;
	while(p != NULL)
	{
		t = p;
		p = p->next;
		t->next = q;
		q = t;
	}
	cout << "Inverse the list successful!" << endl;
	return t;
}

int main()
{
	plist head;
	head = initlist();
	cout << "Please input the sum of the numbers:" << endl;
	int n;
	cin >> n;
	cout << "Please input the numbers:" << endl;
	int m;
	for(int i = 1; i <= n; i++)
	{
		cin >> m;
		insertlist(head, i, m);
	}
	printlist(head);
	cout << "Please input the positions of the numbers you want to delete(input 0 to break the loop):" << endl;
	while(cin >> n, n)
		deletelist(head, n);
	printlist(head);
	cout << "Please input the numbers you want to insert at head(input 0 to break the loop):" << endl;
	while(cin >> n, n)
		insertlist(head, 1, n);
	printlist(head);
	head = inverselist(head);
	printlist(head);
	clearlist(head);
	printlist(head);
	return 0;
}