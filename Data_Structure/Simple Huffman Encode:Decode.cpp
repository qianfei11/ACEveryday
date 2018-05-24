#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#define n 15
#define m 2 * n - 1

typedef struct //½áµãÀàÐÍ
{
    float weight;
    int lchild, rchild, parent;
}htnode;
typedef htnode huffmantree[m];
typedef struct
{
    char bits[n + 1];
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
        t[i].weight = data[i];
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
{
    int p1, p2;
    inithuffmantree(t);
    inputweight(t);
    for(int i = n; i < m; i++)
    {
        selectmin(t, i - 1, &p1, &p2);
        t[p1].parent = t[p2].parent = i;
        t[i].lchild = p1;
        t[i].rchild = p2;
        t[i].weight = t[p1].weight + t[p2].weight;
    }
}

void charsethuffmanencoding(huffmantree t,huffmancode h)
{
    int c, p;
    char cd[n + 1];
    int start;
    cd[n] = '\0';
    for(int i = 0; i < n; i++)
    {
        start = n;
        c = i;
        while((p = t[c].parent) != NULL)
        {
            cd[--start] = (t[p].lchild == c) ? '0' : '1';
            c = p;
        }
        strcpy(h[i].bits, &cd[start]);
    }
    for(int i = 0; i < n; i++)
        printf("The No.%d string %s can be compressed as %s\n", i + 1, str[i], h[i].bits);
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
    printf("%s\n", data);
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
    printf("%s\n", data);
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