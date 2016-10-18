#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int max_n=0x1fff;
int nums[max_n];//the input sequence
int dp[max_n];//dp array
int n;//the length of input sequence
void solve()
{
	//initialize dp[0] to 1, it means we only get nums[0]
	dp[0]=1;
	for(int i=1;i<n;++i)
	{
		dp[i]=1;//initialization
		for(int j=0;j<i;++j)
		{
			//dp equation
			if(nums[i]>nums[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
	}
	//output the answer
	cout<<dp[n-1]<<endl;
	//clear the buffer
	memset(dp,0,max_n);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>n)
	{
		//get the input
		for(int i=0;i<n;++i)
			cin>>nums[i];
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
