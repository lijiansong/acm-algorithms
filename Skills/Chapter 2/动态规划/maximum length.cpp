#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int max_n = 0x1fff;
int nums[max_n];//the input sequence
int maxIndex = 0, curMax = 1;//current maximum length
int dp[max_n];//dp array
int previous[max_n];//extra array to record the backward index
int n;//the length of input sequence
int ans[max_n];//store the answer;
void solve()
{
	//initialize dp[0] to 1, it means we only get nums[0]
	dp[0] = 1;
	previous[0] = -1;
	for(int i=0;i<n;++i)
	{
		dp[i] = 1;
	previous[i] = -1;
	}
	for (int i = 1; i < n; ++i)
	{
		//initialization
		//dp[i] = 1;
		//previous[i] = -1;
		for (int j = 0; j<i; ++j)
		{
			//dp equation
			if (nums[i]>nums[j]&&dp[i]<dp[j]+1)
			{
				dp[i] = dp[j] + 1;
				if (dp[i]>=curMax)
				{
					//update current max index 
					curMax = dp[i];
					previous[i] = j;
					maxIndex = i;
				}
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;++i)
	{
		cout<<previous[i]<<" ";
	}
	cout<<endl;
	//output the answer
	//cout<<curMax<<endl;
	//backward to get the sequence
	ans[0] = nums[maxIndex];
	int index = previous[maxIndex];
	int i = 1;
	while (index != -1)
	{
		ans[i] = nums[index];
		index = previous[index];
		++i;
	}
	for (int j = i - 1; j >= 0; --j)
		cout << ans[j] << " ";
	cout << endl;
	//clear the buff
	memset(dp, 0, max_n);
	memset(previous,-1,max_n);
	memset(ans,0,max_n);
}
int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
	while (cin >> n)
	{
		//get the input
		for (int i = 0; i < n; ++i)
			cin >> nums[i];
		solve();
	}
	fclose(stdin);
	//fclose(stdout);
	return 0;
}
