#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}linkstack, *plinkstack;

plinkstack init()
{
    plinkstack head = (plinkstack)malloc(sizeof(linkstack));
    if(head == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

int isempty(plinkstack s)
{
    return s ? 0 : 1;
}

int gettop(plinkstack s)
{
    if(isempty(s))
    {
        printf("Empty!\n");
        return 0;
    }
    return s->data;
}

plinkstack push(plinkstack s, int x)
{
    plinkstack p;
    p = (plinkstack)malloc(sizeof(linkstack));
    p->data = x;
    p->next = s;
    s = p;
    return s;
}

plinkstack pop(plinkstack s)
{
    plinkstack p;
    if(isempty(s))
    {
        printf("Empty!\n");
        return NULL;
    }
    p = s;
    s = s->next;
    free(p);
    return s;
}

void travel(plinkstack s)
{
    plinkstack p;
    for(p = s; p != NULL; p = p->next)
        printf("%d\n", p->data);
    printf("\n");
}

int main()
{
    plinkstack top;
    top = init();
    while(1)
    {
        printf("1:Push\n2:Pop\n3:Traverse the stack\n4:Get top\n5:Exit\nPlease choose:\n");
        int a, x;
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                printf("Please input the number you want to push:\n");
                scanf("%d", &x);
                top = push(top, x);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                travel(top);
                break;
            case 4:
                printf("%d\n", gettop(top));
                break;
            case 5:
                return 1;
            default: printf("Wrong input!\n");
        }
    }
}