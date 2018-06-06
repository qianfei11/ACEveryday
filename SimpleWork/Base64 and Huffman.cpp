#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
#define MAX 1000
#define n 65
#define m 2 * n - 1

typedef struct
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

int data[66];
char str[66][100] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
                     "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
                     "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "/", "="};
const char *base64payload = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

int find_pos(char c)
{
    for(int i = 0; i < 65; i++)
        if(c == base64payload[i])
            return i;
    return -1;
}

unsigned char *base64_encode(const char *s, const int len)
{
    unsigned int sign = len % 3;
    unsigned int res_len = len % 3 ? ((len) / 3 + 1) * 4 : (len) / 3 * 4;
    unsigned int i = 0, j = 0;
    unsigned char *res = (unsigned char *)malloc(res_len + 1);
    memset(res, 0, res_len + 1);
    for(i = 0, j = 0; i < len; i += 3, j += 4)
    {
        if(i + 2 >= len)
        {
            res[j] = (s[i] >> 2) & 0x3F;
            if(sign == 1)
            {
                res[j + 1] = ((s[i] & 0x03) << 4) & 0x3F;
                res[j + 2] = 0x40;
                res[j + 3] = 0x40;
            }
            else if(sign == 2)
            {
                res[j + 1] = (((s[i] & 0x03) << 4) | ((s[i + 1] >> 4) & 0x0F));
                res[j + 2] = ((s[i + 1] & 0x0F) << 2) & 0x3F;
                res[j + 3] = 0x40;
                break;
            }
        }
        res[j] = (s[i] >> 2) & 0x3F;
        res[j + 1] = (((s[i] & 0x03) << 4) | ((s[i + 1] >> 4) & 0x0F));
        res[j + 2] = (((s[i + 1] & 0x0F) << 2) | ((s[i + 2] >> 6) & 0x03));
        res[j + 3] = (s[i + 2] & 0x3F);
    }
    for(j = 0; j < res_len; j++)
        res[j] = base64payload[res[j]];
    return res;
}

unsigned char *base64_decode(const char *s, const int len)
{
    unsigned int res_len = len / 4 * 3;
    unsigned int i = 0, j = 0;
    unsigned char *res = (unsigned char *)malloc(res_len + 1);
    memset(res, 0, res_len + 1);
    int count = len / 4;
    for(i = 0; i < count; i++)
    {
        int s_index = i * 4;
        int res_index = i * 3;
        int buff[4];
        int sign = 0;
        for(j = 0; j < 4; j++)
            buff[j] = find_pos(s[s_index + j]);
        if(i == count - 1)
            for(j = 0; j < 4; j++)
                if(buff[j] == 0x40)
                    sign++;
        res[res_index] = ((buff[0] & 0x3F) << 2 | (buff[1] & 0x30) >> 4);
        if(sign == 2)
            break;
        res[res_index + 1] = ((buff[1] & 0x0f) << 4 | (buff[2] & 0x3C) >> 2);
        if(sign == 1)
            break;
        res[res_index + 2] = ((buff[2] & 0x03) << 6 | (buff[3] & 0x3F));
    }
    return res;
}

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
}

int binary_to_ascii(char s[8])
{
    int sum = 0;
    for(int i = 0; i < 8; i++)
        if(s[i] == '1')
            sum += (pow(2, 7 - i));
    return sum;
}

char *ascii_to_binary(int num)
{
    char *tmp = (char *)malloc(sizeof(char) * 8);
    memset(tmp, '0', sizeof(tmp));
    int k = 0;
    while(num)
    {
        if(num % 2 == 1)
            tmp[k++] = '1';
        else
            tmp[k++] = '0';
        num /= 2;
    }
    for(int i = 0; i < 4; i++)
    {
        char t = tmp[i];
        tmp[i] = tmp[7 - i];
        tmp[7 - i] = t;
    }
    return tmp;
}

int main()
{
    FILE *fp1;
    fp1 = fopen("1.txt", "r");
    if(fp1 == NULL)
    {
        printf("File open error!\n");
        return 0;
    }
    char ch_temp[MAX], info[MAX];
    while(fgets(ch_temp, MAX, fp1))
        strcat(info, ch_temp);
    fclose(fp1);
    printf("%s\n", info);
    unsigned char string_input[MAX];
    strcpy((char *)string_input, info);
    unsigned char *string = base64_encode((const char *)string_input, strlen((const char *)string_input));
    printf("\nAfter Base64 Encode:\n%s\n", string);
    memset(data, 0, sizeof(data));
    for(int i = 0; i < strlen((char *)string); i++)
    {
        if(isupper(string[i]))
            data[string[i] - 'A']++;
        else if(islower(string[i]))
            data[string[i] - 'a' + 26]++;
        else if(isdigit(string[i]))
            data[string[i] - '0' + 52]++;
        else if(string[i] == '+')
            data[63]++;
        else if(string[i] == '/')
            data[64]++;
        else if(string[i] == '=')
            data[65]++;
        else
        {
            printf("Error!\n");
            break;
        }
    }
    huffmantree t;
    huffmancode h;
    createhuffmantree(t);
    charsethuffmanencoding(t, h);
    int int_temp = 0;
    char after_huffman[MAX];
    memset(after_huffman, 0, sizeof(after_huffman));
    while(int_temp < strlen((char *)string))
    {
        memset(ch_temp, 0, sizeof(ch_temp));
        int k = 0;
        ch_temp[k++] = string[int_temp];
        ch_temp[k] = '\0';
        for(int i = 0; i < n; i++)
            if(strcmp(str[i], ch_temp) == 0)
                strcat(after_huffman, h[i].bits);
        int_temp++;
    }
    printf("\nAfter huffman:\n%s\n", after_huffman);
    char secret_key[MAX];
    int counts[MAX];
    int count = 0;
    for(int i = 0; i < strlen(after_huffman); i += 8)
    {
        char eight_bit[8];
        memset(eight_bit, 0, sizeof(eight_bit));
        for(int j = 0; j < 8; j++)
            eight_bit[j] = after_huffman[i + j];
        int t = binary_to_ascii(eight_bit);
        counts[count] = t;
        secret_key[count] = (char)t;
        count++;
    }
    printf("\nTurn to ascii:\n%s\n", secret_key);
    FILE *fp2;
    fp2 = fopen("1_encode.txt", "w");
    if(fp2 == NULL)
    {
        printf("File open error!\n");
        return 0;
    }
    fprintf(fp2, secret_key);
    fclose(fp2);
    char ascii_to_bin[MAX];
    memset(ascii_to_bin, 0, sizeof(ascii_to_bin));
    for(int i = 0; i < count; i++)
    {
        char *eight_bit = ascii_to_binary(counts[i]);
        strcat(ascii_to_bin, eight_bit);
    }
    ascii_to_bin[strlen(after_huffman)] = '\0';
    printf("\nTurn to binary:\n%s\n", ascii_to_bin);
    char before_huffman[MAX], bin[MAX];
    int_temp = 0;
    while(strlen(ascii_to_bin) > int_temp)
    {
        int k = 0, flag = 0, pos = 0;
        memset(bin, 0, sizeof(bin));
        for(int i = int_temp; i < strlen(ascii_to_bin); i++)
        {
            bin[k++] = ascii_to_bin[i];
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
        strcat(before_huffman, str[pos]);
        int_temp += k;
    }
    printf("\nBefore huffman:\n%s\n", before_huffman);
    unsigned char *final_res = base64_decode((const char *)before_huffman, strlen((const char *)before_huffman));
    printf("\nAfter Base64 Decode:\n%s\n", final_res);
    free(string);
    free(final_res);
    return 0;
}