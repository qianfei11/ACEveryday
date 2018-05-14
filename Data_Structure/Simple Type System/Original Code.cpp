#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAX 200

int cmp(char *s1, char *s2)
{
    int cor = 0;
    for(int i = 0; i < strlen(s1); i++)
        if(s2[i] == s1[i])
            cor++;
    return cor;
}

int main()
{
    char s1[MAX], s2[MAX];
    int sum = 0, cor = 0;
    FILE *fp = fopen("1.txt", "r");
    if(fp == NULL)
    {
        printf("File opened error!\n");
        return 0;
    }
    while(fgets(s1, MAX, fp) != NULL)
    {
        memset(s2, 0, sizeof(s2));
        printf("%s", s1);
        gets(s2);
        sum += strlen(s2);
        cor += cmp(s1, s2);
        if(cmp(s1, s2) + 1 != strlen(s1))
            printf("Wrong input!\n");
    }
    printf("Your correct rate is %lf\n", (double)cor / (double)sum);
    fclose(fp);
    return 0;
}