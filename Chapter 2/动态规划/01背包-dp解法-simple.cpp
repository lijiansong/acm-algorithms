#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N=101;
const int MAX_W=10001;
int dp[MAX_N][MAX_W];
int weight[MAX_N]={0},value[MAX_N]={0},n,max_w;
void solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=n-1;i>=0;--i)
	{
		for(int j=0;j<=max_w;++j)
		{
			if(j<weight[i])
				dp[i][j]=dp[i+1][j];
			else
				dp[i][j]=max(dp[i+1][j],dp[i+1][j-weight[i]]+value[i]);
		}
	}
	cout<<dp[0][max_w]<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while (cin>>n&&n)
	{
		for(int i=0;i<n;++i)
			cin>>weight[i]>>value[i];
		cin>>max_w;
		solve();
	}
	fclose(stdin);
	return 0;
}

