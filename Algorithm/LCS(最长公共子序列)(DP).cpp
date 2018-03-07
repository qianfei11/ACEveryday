#include<iostream>
#include<cstring>
using namespace std;

int dp[100][100];
int map[100][100];

void lcs(char *x, int m, char *y, int n)
{
	map[0][0] = 0;
	for(int i = 1; i <= m; i++)
		map[i][0] = 0;
	for(int i = 1; i <= n; i++)
		map[0][i] = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(x[i - 1] == y[j - 1])
			{
				map[i][j] = map[i - 1][j - 1] + 1;
				dp[i][j] = 0;//向左上搜索
			}
			else if(map[i - 1][j] >= map[i][j - 1])
			{
				map[i][j] = map[i - 1][j];
				dp[i][j] = 1;//向上搜索
			}
			else
			{
				map[i][j] = map[i][j - 1];
				dp[i][j] = -1;//向左搜索
			}
		}
	}
}

void print(int m, int n, char *s)
{
	if(m == 0 || n == 0)
		return;
	if(dp[m][n] == 0)
	{
		print(m - 1, n - 1, s);
		printf("%c", s[m - 1]);
	}
	else if(dp[m][n] == 1)
		print(m - 1, n, s);
	else
		print(m, n - 1, s);
}

int main()
{
	char *x = "xyz";//测试字符串1
	char *y = "xzyxyz";//测试字符串2
	int m = strlen(x), n = strlen(y);
	lcs(x, m, y, n);
	printf("The string is: ");
	if(m <= n)
		print(m, n, x);
	else
		print(m, n, y);
	printf("\nThe length is: %d\n", map[m][n]);//map[m][n]即为最长公共子序列的长度
	return 0;
}
