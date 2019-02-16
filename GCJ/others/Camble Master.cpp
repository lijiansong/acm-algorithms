/*
	Name: 
	Copyright: 
	Author: 
	Date: 20/09/16 19:09
	Description: ¶þ·ÖËÑË÷ 
*/

#include<iostream>
#include<cmath>
using namespace std;
const int MAX_N=10001;
const double INF=10001.0;
int n,k;
double L[MAX_N];
bool compare(double x)
{
	int num=0;
	for(int i=0;i<n;++i)
	{
		num+=(int)(L[i]/x);
	}
	return num>=k;
}
void solve()
{
	double lb=0,ub=INF;
	for(int i=0;i<100;++i)
	{
		double mid=(lb+ub)/2;
		if(compare(mid))
			lb=mid;
		else
			ub=mid;
		//cout<<ub<<" ";
	}
	printf("%.2lf\n",floor(ub*100)/100);
}
int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%lf",&L[i]);
		}
		solve();
	}
	return 0;
} 
