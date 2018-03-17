#include<iostream>
#include<algorithm>
using namespace std;

int *arr, *longest;
int n;

int lis(int *arr, int l)
{
	for(int i = 0; i < l; i++)
		longest[i] = 1;
	for(int i = 1; i < l; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[j] < arr[i] && longest[i] < longest[j] + 1)
				longest[i] = longest[j] + 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < l; i++)
		ans = max(ans, longest[i]);
	return ans;
}

int main()
{
	while(cin >> n)
	{
		arr = (int *)malloc(sizeof(int) * n);
		longest = (int *)malloc(sizeof(int) * n);
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		cout << lis(arr, n) << endl;
		free(arr);
		free(longest);
	}
	return 0;
}
