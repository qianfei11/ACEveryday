#include <cstdio>
#include <cstdlib>
#define LEN 10

void shellsort(int num[], int len)
{
    int tmp, x;
    for(int d = len / 2; d >= 1; d /= 2)
    {
        for(int i = d; i < len; i++)
        {
            for(tmp = num[i], x = i; x >= d && tmp < num[x - d]; x -= d)
            {
                num[x] = num[x - d];
            }
            num[x] = tmp;
        }
    }
}

int main()
{
    int num[LEN] = {89, 123, 32, 4, 65, 7, 66, 23, 39, 30};
    shellsort(num, LEN);
    for(int i = 0; i < LEN; i++)
        printf("%d ", num[i]);
    return 0;
}