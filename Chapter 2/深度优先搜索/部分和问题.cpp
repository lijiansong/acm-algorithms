/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/16 13:47
	Description: 
	部分和问题 
*/
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAX_N=20;
int a[MAX_N];
int n,k;
//已经从前i项得到了和sum，然后对i项之后的进行分支 
bool dfs(int i,int sum)
{
	//如果前n项都计算过了，则返回sum与k是否相等 
	if(i==n)	return sum==k;
	//不加上a[i]的情况 
	if(dfs(i+1,sum))	return true;
	//加上a[i]的情况 
	if(dfs(i+1,sum+a[i]))	return true;
	//无论是否加上a[i]都不能凑成k就返回false 
	return false;
}
void solve()
{
	if(dfs(0,0))
		printf("Yes\n");
	else
		printf("No\n");
}
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
		}
		cin>>k;
		solve(); 
	}
	return 0;
}
