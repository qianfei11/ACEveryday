#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

typedef struct btnode
{
    char data;
    struct btnode *lchild, *rchild;
}btnode;

btnode *createroot(char c)
{
    btnode *tmp;
    tmp = (btnode *)malloc(sizeof(btnode));
    if(!tmp)
        printf("Memory allocation failed!\n");
    else
    {
        tmp->data = c;
        tmp->lchild = tmp->rchild = NULL;
    }
    return tmp;
}

btnode *insertleftnode(btnode *curnode, char c)
{
    btnode *tmp;
    tmp = (btnode *)malloc(sizeof(btnode));
    if(!tmp)
        printf("Memory allocation failed!\n");
    else
    {
        tmp->data = c;
        tmp->lchild = curnode->lchild;
        tmp->rchild = NULL;
        curnode->lchild = tmp;
    }
    return curnode;
}

void delleftnode(btnode *curnode)
{
    if(curnode->lchild && curnode->rchild)
        return;
    btnode *tmp = curnode->lchild;
    btnode *lc = tmp->lchild ? tmp->lchild : tmp->rchild;
    curnode->lchild = lc;
    free(tmp);
}

btnode *insertrightnode(btnode *curnode, char c)
{
    btnode *tmp;
    tmp = (btnode *)malloc(sizeof(btnode));
    if(!tmp)
        printf("Memory allocation failed!\n");
    else
    {
        tmp->data = c;
        tmp->rchild = curnode->rchild;
        tmp->lchild = NULL;
        curnode->rchild = tmp;
    }
    return curnode;
}

void delrightnode(btnode *curnode)
{
    if(curnode->lchild && curnode->rchild)
        return;
    btnode *tmp = curnode->rchild;
    btnode *lc = tmp->rchild ? tmp->rchild : tmp->lchild;
    curnode->rchild = lc;
    free(tmp);
}

btnode *createtree()
{
    btnode *root;
    char ch;
    scanf("%c", &ch);
    if(ch == '#')
        return NULL;
    else
    {
        root = (btnode *)malloc(sizeof(btnode));
        if(root == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(0);
        }
        root->data = ch;
        root->lchild = createtree();
        root->rchild = createtree();
    }
    return root;
}

void visit(btnode *node)
{
    printf("%c ", node->data);
}

void preordertraverse(btnode * root)
{
    if(root != NULL)
    {
        visit(root);
        preordertraverse(root->lchild);
        preordertraverse(root->rchild);
    }
}

int totalnoleafnodes(btnode *root)
{
    if(root == NULL)
        return 0;
    else if(root->rchild == NULL && root->rchild == NULL)
        return 0;
    else
        return 1 + totalnoleafnodes(root->lchild) + totalnoleafnodes(root->rchild);
}

int treedeep(btnode *root)
{
    if(root == NULL)
        return 0;
    else
    {
        int ld = treedeep(root->lchild);
        int rd = treedeep(root->rchild);
        return ld > rd ? ld + 1 : rd + 1;
    }
}

void inordertraverse(btnode *root)
{
    if(root != NULL)
    {
        inordertraverse(root->lchild);
        visit(root);
        inordertraverse(root->rchild);
    }
}

void postordertraverse(btnode *root)
{
    if(root != NULL)
    {
        postordertraverse(root->lchild);
        postordertraverse(root->rchild);
        visit(root);
    }
}

void leveltraverse(btnode *root)
{
    int childsize = 0, parentsize = 1;
    btnode *tmp;
    queue <btnode *> q;
    q.push(root);
    do
    {
        tmp = q.front();
        visit(tmp);
        q.pop();
        if(tmp->lchild != NULL)
        {
            q.push(tmp->lchild);
            childsize++;
        }
        if(tmp->rchild != NULL)
        {
            q.push(tmp->rchild);
            childsize++;
        }
        parentsize--;
        if(parentsize == 0)
        {
            parentsize = childsize;
            childsize = 0;
            printf("\n");
        }
    }while(!q.empty());
}

int totalnodes(btnode *root)
{
    if(root == NULL)
        return 0;
    else
        return 1 + totalnodes(root->lchild) + totalnodes(root->rchild);
}

int totalleafnodes(btnode *root)
{
    if(root == NULL)
        return 0;
    else if(root->lchild == NULL && root->rchild == NULL)
        return 1;
    else
        return totalleafnodes(root->lchild) + totalleafnodes(root->rchild);
}

btnode* restore_tree(char preorder[], char inorder[], int inorder_left, int inorder_right, int &pre_index)
{
    if(inorder_left > inorder_right)
        return NULL;
    char key = preorder[pre_index++];
    btnode *node = (btnode *)malloc(sizeof(btnode));
    node->data = key;
    if(inorder_left == inorder_right)
        return node;
    int i;
    for(i = inorder_left; inorder[i] != key; ++i);
    node->lchild = restore_tree(preorder, inorder, inorder_left, i-1, pre_index);
    node->rchild = restore_tree(preorder, inorder, i+1, inorder_right, pre_index);
    return node;
}

int main()
{
//    btnode *root1;
//    btnode *curnode;
//    root1 = createroot('A');
//    root1 = insertleftnode(root1, 'B');
//    root1 = insertrightnode(root1, 'C');
//    curnode = root1->rchild;
//    curnode = insertrightnode(curnode, 'D');
//    leveltraverse(root1);
//
//    btnode *root2;
//    root2 = createroot('A');
//    root2 = insertleftnode(root2, 'B');
//    root2 = insertrightnode(root2, 'C');
//    curnode = root2->lchild;
//    curnode = insertleftnode(curnode, 'D');
//    curnode = root2->rchild;
//    curnode = insertleftnode(curnode, 'E');
//    curnode = insertrightnode(curnode, 'F');
//    curnode = curnode->lchild;
//    curnode = insertrightnode(curnode, 'G');
//    leveltraverse(root2);
//
//// 二叉树 1 的先序次序为 AB##CD###
//    btnode *root3;
//    root3 = createtree();
//    printf("%d %d %d %d\n", totalnodes(root3), totalleafnodes(root3), totalnoleafnodes(root3), treedeep(root3));
//    preordertraverse(root3);
//    printf("\n");
//    inordertraverse(root3);
//    printf("\n");
//    postordertraverse(root3);
//    printf("\n");
//    leveltraverse(root3);
//    printf("\n");
//    getchar();

// 二叉树 2 的先序次序为 ABD###CE#G##F##
    btnode *root4;
    root4 = createtree();
    printf("%d %d %d %d\n", totalnodes(root4), totalleafnodes(root4), totalnoleafnodes(root4), treedeep(root4));
    preordertraverse(root4);
    printf("\n");
    inordertraverse(root4);
    printf("\n");
    postordertraverse(root4);
    printf("\n");
    leveltraverse(root4);
    printf("\n");
    getchar();

// 将二叉树 2 的先序和中序遍历字符串保存到两个数组
    btnode *root5;
    char *s1 = "ABDCEGF";
    char *s2 = "DBAEGCF";
    int index = 0;
    root5 = restore_tree(s1, s2, 0, 6, index);
    leveltraverse(root5);
    return 0;
}