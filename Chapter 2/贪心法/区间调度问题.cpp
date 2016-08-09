/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/08/16 08:37
	Description: 
	区间调度问题
	贪心算法 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N=10000;
int n,s[MAX_N],t[MAX_N];
pair<int,int> itv[MAX_N];
void solve()
{
	//对pair进行的是字典序比较
	//为了让结束时间早的任务排在前面，把t存入first，把s存入second 
	for(int i=0;i<n;++i)
	{
		itv[i].first=t[i];
		itv[i].second=s[i];
	}
	sort(itv,itv+n);
	int ans=0,t=0;
	for(int i=0;i<n;++i)
	{
		if(t<itv[i].second)
		{
			ans++;
			t=itv[i].first;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
			cin>>s[i];
		for(int i=0;i<n;++i)
			cin>>t[i];
		solve();
	}
	return 0;
} 

