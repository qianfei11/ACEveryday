#include<stdio.h>
#include<string.h>
#define MAX 101

int next[MAX];

void get_next(char *s)
{
    int len = strlen(s);
    memset(next, 0, sizeof(next));
    next[0] = 0;
    for(int i = 1, j = 0; i < len; i++)
    {
        while(j > 0 && s[i] != s[j])
            j = next[j - 1];
        if(s[i] == s[j])
            j++;
        next[i] = j;
    }
//  for(int i = 0; i < len; i++)
//      printf("%d ", next[i]);
//    printf("\n");
}

int kmp(char *s1, char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    for(int i = 0, j = 0; i < len1; i++)
    {
        while(j > 0 && s2[j] != s1[i])
            j = next[j - 1];
        if(s2[j] == s1[i])
            j++;
        if(j == len2)
            printf("Start at pos %d\n", i - len2 + 1);
    }
}

int main()
{
    char s1[MAX], s2[MAX];
    printf("Please input the father string:\n");
    scanf("%s", s1);
    printf("Please input the son string:\n");
    scanf("%s", s2);
    get_next(s2);
    kmp(s1, s2);
    return 0;
}