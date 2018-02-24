#include<iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = exgcd(b, a % b, x, y);
	int t = y;
	y = x - (a / b) * y;
	x = t; 
	return r;
}
int main()
{
	int x, y, a, b;
	while(cin >> a >> b)
	{
		cout << exgcd(a, b, x, y) << endl;
		cout << x << endl;
		cout << y << endl;
	}
	return 0;
}
