#include<stdio.h>
#include<string.h>
#define MAX 101

int next[MAX];

void get_next(char *s)
{
    int q, k;
    int len = strlen(s);
    memset(next, 0, sizeof(next));
    next[0] = 0;
    for(q = 1, k = 0; q < len; q++)
    {
        while(k > 0 && s[q] != s[k])
            k = next[k - 1];
        if(s[q] == s[k])
            k++;
        next[q] = k;
    }
//	for(int i = 0; i < len; i++)
//		printf("%d ", next[i]);
//    printf("\n");
}

int kmp(char *s1, char *s2)
{
    int i, q;
    int len1 = strlen(s1), len2 = strlen(s2);
    for(int i = 0, q = 0; i < len1; i++)
    {
        while(q > 0 && s2[q] != s1[i])
            q = next[q - 1];
        if(s2[q] == s1[i])
            q++;
        if(q == len2)
            printf("Start at pos %d\n", i - len2 + 1);
    }
}

int main()
{
    int i;
    char s1[MAX], s2[MAX];
    printf("Please input the father string:\n");
    scanf("%s", s1);
    printf("Please input the son string:\n");
    scanf("%s", s2);
    get_next(s2);
    kmp(s1, s2);
    return 0;
}