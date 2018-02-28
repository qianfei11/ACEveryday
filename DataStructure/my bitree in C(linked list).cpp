#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int num;
	struct tree *lc, *rc;
}tree, *ptree;

ptree create()
{
	ptree root;
	int n;
	scanf("%d", &n);
	if(n < 0)
		root = NULL;
	else
	{
		root = (ptree)malloc(sizeof(tree));
		root->num = n;
		root->lc = create();
		root->rc = create();
	}
	return root;
}

void pretravel(ptree root)
{
	if(root == NULL)
		return;
	printf("%d\n", root->num);
	pretravel(root->lc);
	pretravel(root->rc);
}

void intravel(ptree root)
{
	if(root == NULL)
		return;
	intravel(root->lc);
	printf("%d\n", root->num);
	intravel(root->rc);
}

void posttravel(ptree root)
{
	if(root == NULL)
		return;
	posttravel(root->lc);
	posttravel(root->rc);
	printf("%d\n", root->num);
}

int leafnum(ptree root)
{
	if(root == NULL)
		return 0;
	if(root->lc == NULL && root->rc == NULL)
		return 1;
	else
		return leafnum(root->lc) + leafnum(root->rc);
}

int nodenum(ptree root)
{
	if(root == NULL)
		return 0;
	else
		return nodenum(root->lc) + nodenum(root->rc) + 1;
}

int depth(ptree root)
{
	if(root == NULL)
		return 0;
	else
		return depth(root->lc) > depth(root->rc) ? depth(root->lc) + 1 : depth(root->rc) + 1;
}

int main()
{
//	ptree root;
//	root = create();
//	pretravel(root);
//	printf("\n");
//	intravel(root);
//	printf("\n");
//	posttravel(root);
//	printf("\n");
//	printf("%d %d %d\n", leafnum(root), nodenum(root), depth(root));
	return 0;
}
