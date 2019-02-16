/*
	Name: 
	Copyright: 
	Author: 
	Date: 21/09/16 16:27
	Description: ³ßÈ¡·¨ O(n) 
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N=100001;
int n,s;
int a[MAX_N];
void solve()
{
	int res=n+1;
	int ss=0,t=0,sum=0;
	for(;;)
	{
		while(t<n && sum<s)
		{
			sum+=a[t++];
		}
		if(sum<s) break;
		res=min(res,t-ss);
		sum-=a[ss++];
	}
	if(res>n)
	{
		res=0;
	}
	printf("%d\n",res);
}
int main()
{
	freopen("sub.txt","r",stdin); 
	while(scanf("%d %d",&n,&s)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
} 
