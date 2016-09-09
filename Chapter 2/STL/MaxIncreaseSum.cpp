#include <iostream>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	const int MAX_N = 100;
	int a[MAX_N] = { 0 };
	int n;
	while (cin>>n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}

		int ThisSum = 0, MaxSum = 0;
		for (int j = 0; j < n; ++j)
		{
			ThisSum += a[j];
			if (ThisSum>MaxSum)
			{
				MaxSum = ThisSum;
			}
			else if (ThisSum < 0)
			{
				ThisSum = 0;
			}
		}
		cout << MaxSum << endl;
	}
	system("pause");
	return 0;
}