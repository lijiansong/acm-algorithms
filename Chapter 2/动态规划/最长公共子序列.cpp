#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAX_N=1000;
const int MAX_M=1000;
char s[MAX_N],t[MAX_M];
int n,m,dp[MAX_N][MAX_M];
void solve()
{
	dp[0][0]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(s[i+1]=t[i+1])
			{
				dp[i+1][j+1]=dp[i][j]+1;
			}
			else
			{
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
	cout<<dp[n][m]<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>n>>m)
	{
		for(int i=0;i<n;++i)
			cin>>s[i];
		for(int j=0;j<m;++j)
			cin>>t[j];
		solve();
	}
	return 0;
} 
