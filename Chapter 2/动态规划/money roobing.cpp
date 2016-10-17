#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int max_n=100;
int dp[max_n];
int v[max_n];
int n;
void solve()
{
	dp[0]=v[0];dp[1]=max(v[0],v[1]);
	for(int i=2;i<n;++i)
	{
		dp[i]=max(dp[i-1],dp[i-2]+v[i]);
	}
	cout<<dp[n-1]<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
			cin>>v[i];
		solve();
	}
	return 0;
} 
