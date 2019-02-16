#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N=100001;
int n,s;
int a[MAX_N];
int sum[MAX_N]={0};
void solve()
{
	for(int i=0;i<n;++i)
	{
		sum[i+1]=sum[i]+a[i];
	}
	if(sum[n]<s)
	{
		printf("0\n");
		return ;
	}
	int res=n;
	for(int ss=0;sum[ss]+s<=sum[n];++ss)
	{
		int t=lower_bound(sum+ss,sum+n,sum[ss]+s)-sum;
		res=min(res,t-ss);
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
