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

void qtravel(ptree root)
{
	if(root == NULL)
		return;
	printf("%d\n", root->num);
	qtravel(root->lc);
	qtravel(root->rc);
}

void ztravel(ptree root)
{
	if(root == NULL)
		return;
	ztravel(root->lc);
	printf("%d\n", root->num);
	ztravel(root->rc);
}

void htravel(ptree root)
{
	if(root == NULL)
		return;
	htravel(root->lc);
	htravel(root->rc);
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
//	qtravel(root);
//	printf("\n");
//	ztravel(root);
//	printf("\n");
//	htravel(root);
//	printf("\n");
//	printf("%d %d %d\n", leafnum(root), nodenum(root), depth(root));
	return 0;
}
