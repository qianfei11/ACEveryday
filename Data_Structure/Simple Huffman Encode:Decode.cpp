#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#define n 15 //叶子数目
#define m 2 * n - 1 //树中结点总数

typedef struct //结点类型
{
    float weight;
    int lchild, rchild, parent;
}htnode;
typedef htnode huffmantree[m]; //huffmantree 是向量类型
typedef struct
{
    char bits[n + 1]; //存放编码位串
}codenode;
typedef codenode huffmancode[n];

int data[15] = {40, 10, 6, 50, 32, 12, 5, 20, 18, 12, 30, 10, 25, 8, 36};
char str[15][100] = {"love", "is", "this", "commandment", "always", "said", "by", "Marbury", "which", "means", "that", "one", "person", "any", "other"};

void inithuffmantree(huffmantree t)
{
    for(int i = 0; i < m; i++)
    {
        t[i].weight = 0;
        t[i].lchild = t[i].rchild = t[i].parent = NULL;
    }
}

void inputweight(huffmantree t)
{
    for(int i = 0; i < n; i++)
    {
//        printf("请输入第%d个权值：\n", i + 1);
//        scanf("%f", &t[i].weight);
        t[i].weight = data[i];
    }
}

void selectmin(huffmantree t, int i, int *p1, int *p2)
{
    float min1, min2;
    min1 = min2 = -1;
    for(int j = 0; j <= i; j++)
    {
        if(t[j].parent == NULL)
        {
            if(t[j].weight < min1 || min1 == -1)
            {
                if(min1 != -1)
                {
                    min2 = min1;
                    *p2 = *p1;
                }
                min1 = t[j].weight;
                *p1 = j;
            }
            else if(t[j].weight < min2 || min2 == -1)
            {
                min2 = t[j].weight;
                *p2 = j;
            }
        }
    }
}

void createhuffmantree(huffmantree t)
{ //构造huffman 树，t[m-1]为其根结点
    int p1, p2;
    inithuffmantree(t);
    inputweight(t);
    for(int i = n; i < m; i++) //共进行n-1 次合并，新结点依次存于t[i]中
    {
        selectmin(t, i - 1, &p1, &p2);
//在t[0..i-1]中选择两个权最小的根结点，其序号分别为p1 和p2
        t[p1].parent = t[p2].parent = i;
        t[i].lchild = p1; //最小权的根结点是新结点的左孩子
        t[i].rchild = p2; //次小权的根结点是新结点的右孩子
        t[i].weight = t[p1].weight + t[p2].weight;
    }
}

void charsethuffmanencoding(huffmantree t,huffmancode h)
{
    int c, p;
    char cd[n + 1]; //临时存放编码
    int start; //指示编码在cd 中的起始位置
    cd[n] = '\0'; //编码结束符
    for(int i = 0; i < n; i++) //依次求叶子t[i]的编码
    {
        start = n; //编码起始位置的初值
        c = i; //从叶子t[i]开始上溯
        while((p = t[c].parent) != NULL)//直至上溯到t[c]是树根为止
        { //若t[c]是t[p]的左孩子，则生成代码0；否则生成代码1
            cd[--start] = (t[p].lchild == c) ? '0' : '1';
            c = p; //继续上溯
        }
        strcpy(h[i].bits, &cd[start]); //复制编码位串
    }
    for(int i = 0; i < n; i++)
        printf("第%d个单词%s的编码为%s\n", i + 1, str[i], h[i].bits);
}

int binary_to_ascii(char s[8])
{
    int sum = 0;
    for(int i = 0; i < 8; i++)
        if(s[i] == '1')
            sum += (pow(2, 7 - i));
    return sum;
}

int main()
{
    huffmantree t;
    huffmancode h;
    createhuffmantree(t);
    charsethuffmanencoding(t, h);
//    char s1[200] = "love is love, this commandment is always said by Marbury, which means that one person always love any other person.";
    char s1[200] = "love is love this commandment is always said by Marbury which means that one person always love any other person";
    char data[800], s2[100];
    int tmp = 0;
//    for(int i = 0; i < n; i++)
//        printf("%s %s\n", str[i], h[i].bits);
    while(tmp < strlen(s1))
    {
        memset(s2, 0, sizeof(s2));
        int k = 0;
        for(int i = tmp; i < strlen(s1); i++)
        {
            if(isalpha(s1[i]))
                s2[k++] = s1[i];
            else
                break;
        }
        s2[k] = '\0';
//        printf("%s\n", s2);
        tmp += (k + 1);
        for(int i = 0; i < n; i++)
            if(strcmp(s2, str[i]) == 0)
                strcat(data, h[i].bits);
//                printf("%s\n", h[i].bits);
    }
//    printf("%s\n", data);
    printf("压缩结果：");
    for(int i = 0; i < strlen(data); i += 8)
    {
        char tmp[8];
        memset(tmp, 0, sizeof(tmp));
        for(int j = 0; j < 8; j++)
            tmp[j] = data[i + j];
        int t = binary_to_ascii(tmp);
//        printf("%d", t);
        printf("%c", (char)t);
    }
    printf("\n");
    tmp = 0;
    char bin[200];
    char res[200];
    while(tmp < strlen(data))
    {
        int k = 0, flag = 0, pos = 0;
        memset(bin, 0, sizeof(bin));
        for(int i = tmp; i < strlen(data); i++)
        {
            bin[k++] = data[i];
            for(int j = 0; j < n; j++)
            {
                if(strcmp(bin, h[j].bits) == 0)
                {
                    flag = 1;
                    pos = j;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        strcat(res, str[pos]);
        strcat(res, " ");
        tmp += k;
    }
    printf("解压缩结果：%s\n", res);
    return 0;
}