#include<cstdio>
#include<cstdlib>
#include<cstring>

typedef struct
{
    char *ch;
    int length;
}mstring;

void initstring(mstring *s)
{
    s->ch= 0;
    s->length= 0;
}

void assignstring(mstring *s, char *cs)
{
    int len = strlen(cs);
    if(s->length != len)
    {
        if(!s->ch)
        {
            free(s->ch);
        }
        s->ch = (char *)malloc(sizeof(char) * len);
    }
    memcpy(s->ch, cs, sizeof(char) * len);
    s->length = len;
}

int comparestring(mstring *s, mstring *t)
{
    int cmpsize = (s->length <= t->length ? s->length : t->length);
    for(int i = 0; i < cmpsize; i++)
    {
        if(s->ch[i] > t->ch[i])
            return 1;
        else if(s->ch[i] < t->ch[i])
            return -1;
        else
            continue;
    }
    if(s->length == t->length)
        return 0;
    else if(s->length < t->length)
        return -1;
    else
        return 1;
}

char strat(mstring *s, int pos)
{
    if((pos < 1) || (pos > s->length))
    {
        printf("Your pos is illegal!\n");
        return NULL;
    }
    return s->ch[pos - 1];
}

int substring(mstring *sub, mstring *s, int pos, int len)
{
//    if((pos < 1) || (pos + len + 1 > s->length))
//    {
//        printf("Your pos is illegal!\n");
//        return 0;
//    }
    int k = 0;
    sub->ch = (char *)malloc(sizeof(char) * len);
    for(int i = pos - 1; i < pos + len + 1; i++)
        sub->ch[k++] = s->ch[i];
    sub->length = len;
    sub->ch[sub->length] = '\0';
    return 1;
}

void concatstring(mstring *t, mstring *s1, mstring *s2)
{
    char *str;
    str = (char *)malloc(sizeof(char) * (s1->length + s2->length));
    for(int i = 0; i < s1->length; i++)
        str[i] = s1->ch[i];
    int k = 0;
    for(int i = s1->length; i < s2->length; i++)
        str[i] = s2->ch[k++];
    assignstring(t, str);
}

void clearstring(mstring *s)
{
    free(s->ch);
    s->length = 0;
}

int subindex(mstring *s, mstring *t, int pos)
{
    mstring sub;
    initstring(&sub);
    for(int i = pos; i <= s->length; i++)
    {
        if(substring(&sub, s, i, t->length) == 0)
            return 0;
        if(comparestring(&sub, t) == 0)
            return i;
    }
    clearstring(&sub);
    return 0;
}

int main()
{
    mstring s1, s2;
    initstring(&s1);
    initstring(&s2);
    char str[100];
    printf("Please input string1:\n");
    scanf("%s", str);
    assignstring(&s1, str);
    printf("Please input string2:\n");
    scanf("%s", str);
    assignstring(&s2, str);
    int flag = comparestring(&s1, &s2);
    if(flag > 0)
        printf("\"%s\" is bigger!\n", s1.ch);
    else if(flag < 0)
        printf("\"%s\" is bigger!\n", s2.ch);
    else
        printf("They are the same!\n");
    printf("Please input string1:\n");
    scanf("%s", str);
    assignstring(&s1, str);
    printf("Please input string2:\n");
    scanf("%s", str);
    assignstring(&s2, str);
    int pos;
    printf("Please input the pos you want to start:\n");
    scanf("%d", &pos);
    int sign = subindex(&s1, &s2, 0);
    if(sign == 0)
        printf("No substring.\n");
    else
        printf("Find it at pos %d.\n", sign);
    return 0;
}