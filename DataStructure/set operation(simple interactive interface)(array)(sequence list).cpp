#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct{
	int *elem;
	int len;
}seqlist;

void init(seqlist *list, int n)
{
	list->len = 0;
	list->elem = (int *)malloc(sizeof(int) * n);
	if(list->elem == NULL)
	{
		cout << "Memory allocation failed!" << endl;
		exit(0);
	}
	memset(list->elem, 0, sizeof(list->elem));
}

int insert(seqlist *list, int pos, int n)
{
	int t = 0;
	if(pos < 0 || pos > list->len)
	{
//		cout << "Your pos is wrong!" << endl;
		return 0;
	}
	for(t = list->len; t >= pos; t--)
		list->elem[t + 1] = list->elem[t];
	list->elem[pos] = n;
	list->len++;
//	cout << "insert suc" << endl;
	return pos;
}

int get(seqlist *list, int pos)
{
	if(pos < 0 || pos >= list->len)
	{
//		cout << "Your pos is wrong!" << endl;
		return 0;
	}
	return list->elem[pos];
}

int del(seqlist *list, int pos)
{
	if(pos < 0 || pos >= list->len)
	{
//		cout << "Your pos is wrong!" << endl;
		return 0;
	}
	for(int i = pos + 1; i < list->len; i++)
		list->elem[i - 1] = list->elem[i];
	list->len--;
	return 1;
}

int find(seqlist *list, int x)
{
	for(int i = 0; i < list->len; i++)
	{
		if(list->elem[i] == x)
		{
//			cout << "Find " << x << "!" << endl;
			return i;
		}
	}
//	cout << "Can\'t find " << x << "!" << endl;
	return 0;
}

int length(seqlist *list)
{
	int sum = 0;
	for(int i = 0; i < list->len; i++)
		sum++;
	return sum;
}

void print(seqlist *list)
{
	for(int i = list->len - 1; i >= 0; i--)
		cout << list->elem[i] << endl;
}

void unionset(seqlist *a, seqlist *b)
{
	int lena, lenb, t;
	lena = length(a);
	lenb = length(b);
	for(int i = 0; i < lenb; i++)
	{
		t = get(b, i);
		if(!find(a, t))
		{
			insert(a, 0, t);
			lena++;
		}
	}
}

void intersectset(seqlist *a, seqlist *b, seqlist *c)
{
	int lena, lenb, lenc, t;
	lena = length(a);
	lenb = length(b);
	lenc = length(c);
	for(int i = 0; i < lenb; i++)
	{
		t = get(b, i);
		if(find(a, t))
			insert(c, 0, t);
	}
}

int main()
{
	int n, m;
	seqlist a;
	cout << "Please input the sum of numbers:" << endl;
	cin >> n;
	init(&a, n);
	cout << "Please input the numbers:" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		insert(&a, i, m);
	}
	cout << endl;
	cout << "Please input the numbers and positions you want to insert(input 0 to break the loop):" << endl;
	while(cin >> n >> m, m && n)
		insert(&a, m, n);
	print(&a);
	cout << endl;
	cout << "Please input the numbers you want to delete(input 0 to break the loop):" << endl;
	while(cin >> n, n)
		del(&a, n);
	print(&a);
	cout << endl;
	cout << "Please input the numbers you want to find(input 0 to break the loop):" << endl;
	while(cin >> n, n)
		find(&a, n);
	cout << endl;
	cout << "The length of the sequence list is:" << length(&a) << endl;
	
	seqlist x, y;
	cout << "Please input the sum of numbers in the first set:" << endl;
	cin >> n;
	init(&x, n);
	cout << "Please input the numbers:" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		insert(&x, i, m);
	}
	cout << "Please input the sum of numbers in the second set:" << endl;
	cin >> n;
	init(&y, n);
	cout << "Please input the numbers:" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		insert(&y, i, m);
	}
	cout << "union set is:" << endl;
	unionset(&x, &y);
	print(&x);
	
	seqlist c;
	init(&c, 100);
	cout << "Please input the sum of numbers in the first set:" << endl;
	cin >> n;
	init(&x, n);
	cout << "Please input the numbers:" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		insert(&x, i, m);
	}
	cout << "Please input the sum of numbers in the second set:" << endl;
	cin >> n;
	init(&y, n);
	cout << "Please input the numbers:" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		insert(&y, i, m);
	}
	cout << "intersect set is:" << endl;
	intersectset(&x, &y, &c);
	print(&c);
	return 0;
}
