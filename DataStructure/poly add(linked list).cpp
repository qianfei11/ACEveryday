#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct polynode
{
	int exp;
	int coef;
	struct polynode *next;
}poly, *ppoly;

void add_poly(ppoly poly1, ppoly poly2)
{
     ppoly p, q, pre, tmp;
     int sum = 0;
     p = poly1->next;
     q = poly2->next;
     pre = poly1;
     while(p != NULL && q != NULL)
     {
             if(p->exp > q->exp)
             {
                       pre->next = p;
                       pre = pre->next;
                       p = p->next;
             }
             else if(p->exp == q->exp)
             {
                  sum = p->coef + q->coef;
                  if(sum != 0)
                  {
                         p->coef = sum;
                         pre->next = p;
                         pre = pre->next;
                         p = p->next;
                         tmp = q;
                         q = q->next;
                         free(tmp);
                  }
                  else
                  {
                      tmp = p->next;
                      free(p);
                      p = tmp;
                      tmp = q->next;
                      free(q);
                      q = tmp;
                  }
             }
             else
             {
                 pre->next = q;
                 pre = pre->next;
                 q = q->next;
             }
     }
     if(p != NULL)
          pre->next = p;
     else
         pre->next = q;
}

ppoly create_poly()
{
      ppoly head, tail, p;
      int exp, coef;
      head = (ppoly)malloc(sizeof(poly));
      head->next = NULL;
      tail = head;
      cin >> coef >> exp;
      while(coef != 0 && exp != 0)
      {
                 p = (ppoly)malloc(sizeof(poly));
                 if(p == NULL)
                 {
                      cout << "memory allocation failed!" << endl;
                      exit(0);
                 }
                 p->exp = exp;
                 p->coef = coef;
                 p->next = NULL;
                 tail->next = p;
                 tail = p;
                 cin >> coef >> exp;
      }
      return head;
}

void print_poly(ppoly head)
{
	ppoly p = head->next;
	while(p != NULL)
	{
		cout << p->coef << "*x^" << p->exp << endl;
		p = p->next;
	}
}

int main()
{
    ppoly p1, p2;
    cout << "please input coef and exp from large to small(input 0 and 0 to break the loop):" << endl;
    cout << "please input the first ploy:" << endl;
    p1 = create_poly();
    cout << "please input the second ploy:" << endl;
    p2 = create_poly();
    cout << "the result of two polies add:" << endl;
    add_poly(p1, p2);
    print_poly(p1);
    return 0;
}