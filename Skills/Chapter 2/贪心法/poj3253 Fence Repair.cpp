#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int MAX_N = 20000;
int n, len[MAX_N] = { 0 };
void solve()
{
	int ans = 0;
	while (n>1)
	{
		int min1 = 0, min2 = 1;
		if (len[min1] > len[min2])
			swap(min1, min2);
		for (int i = 2; i < n;++i)
		{
			if (len[i] < len[min1])
			{
				min1 = i;
				min2 = min1;
			}
			else if (len[i] < len[min2])
				min2 = i;
		}
		int t = len[min1] + len[min2];
		ans += t;
		if (min1 == n - 1)
			swap(min1, min2);

		len[min1] = t;
		len[min2] = len[n - 1];
		n--;
	}
	cout << ans << endl;
}
int main()
{
	freopen("in.txt", "r", stdin);
	while (cin>>n&&n)
	{
		for (int i = 0; i < n; ++i)
			cin >> len[i];
		solve();
	}
	fclose(stdin);
	return 0;
}
