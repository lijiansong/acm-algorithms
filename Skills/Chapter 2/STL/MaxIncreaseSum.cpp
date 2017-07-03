#include <iostream>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;
/*long int Pow(long int x,unsigned int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return x;
	else if((x%2)==0)
		return Pow(x*x,n/2);
	else
		return Pow(x*x,n/2)*x;
} */

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
