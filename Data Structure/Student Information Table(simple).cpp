#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct a
{
	char id[12];
	char name[10];
	int gender;
	char classroom[15];
}elemtype;

typedef struct b
{
	elemtype data;
	struct b *next;
}table, *ptable;

ptable init_table()
{
	ptable head = (ptable)malloc(sizeof(table));
	memset(head->data.id, 0, sizeof(head->data.id));
	head->data.gender = 0;
	memset(head->data.name, 0, sizeof(head->data.name));
	memset(head->data.classroom, 0, sizeof(head->data.classroom));
	head->next = NULL;
	return head;
}

int insert_table(ptable head, int pos, elemtype x)
{
	ptable q = 0, p = head;
	int j = 0;
	while (p->next != NULL && j < pos - 1)
	{
		p = p->next;
		j++;
	}
	if (j != pos - 1)
	{
		cout << "Error!" << endl;
		return -1;
	}
	q = (ptable)malloc(sizeof(table));
	strcpy(q->data.id, x.id);
	strcpy(q->data.name, x.name);
	q->data.gender = x.gender;
	strcpy(q->data.classroom, x.classroom);
	q->next = p->next;
	p->next = q;
	return pos;
}

elemtype delete_table(ptable head, int pos)
{
	ptable p = head, pre = NULL;
	for (int i = 0; i < pos; i++)
	{
		pre = p;
		p = p->next;
	}
	pre->next = p->next;
	elemtype x;
	strcpy(x.id, p->data.id);
	strcpy(x.name, p->data.id);
	x.gender = p->data.gender;
	strcpy(x.classroom, p->data.classroom);
	free(p);
	return x;
}

int find_table(ptable head, elemtype x)
{
	ptable p;
	int flag = 0;
	for(p = head; p != NULL; p = p->next)
	{
		if(strcmp(p->data.id, x.id) == 0 && p->data.gender == x.gender && strcmp(p->data.classroom, x.classroom) == 0 && strcmp(p->data.name, x.name) == 0)
			flag = 1;
	}
	if(flag == 1)
	{
		cout << "Find!" << endl;
		return 1;
	}
	else
	{
		cout << "Can\'t find!" << endl;
		return 0;
	}
}

int length_table(ptable head)
{
	int len = 0;
	ptable p;
	for (p = head; p->next != NULL; p = p->next)
		len++;
	return len;
}

void print_table(ptable head)
{
	ptable p = head->next;
	while(p != NULL)
	{
		cout << p->data.id << " " << p->data.name << " " << p->data.gender << " "<< p->data.classroom << endl;
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int n;
	ptable head;
	head = init_table();
	cout << "Please input the sum of the students you want to input:" << endl;
	cin >> n;
	cout << "Please input the students\'s id, name, gender and classroom:" << endl;
	elemtype x;
	for(int i = 0; i < n; i++)
	{
		cin >> x.id >> x.name >> x.gender >> x.classroom;
		insert_table(head, 1, x);
	}
	print_table(head);
	cout << "PLease input the position of students you want to delete(input 0 to break the loop):" << endl;
	while(cin >> n, n)
		x = delete_table(head, n);
	print_table(head);
	cout << "Please input the students\'s id, name, gender and classroom that you want to find:" << endl;
	cin >> x.id >> x.name >> x.gender >> x.classroom;
	find_table(head, x);
	cout << "The length of the table is: " << length_table(head) << endl;
	FILE *fp = fopen("1.txt", "w");
	if(fp == NULL)
	{
		printf("File created failed!\n");
	}
	ptable p = head->next;
	while(p != NULL)
	{
		fprintf(fp, "%s %d %s %s\n", p->data.id, p->data.gender, p->data.name, p->data.classroom);
		p = p->next;
	}
	fclose(fp);
	return 0;
}