#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1<<10;
int main()
{
	freopen("in.txt","r",stdin);
	int n,price[maxn],curProfit[maxn],futureProfit[maxn];
	while(cin>>n)
	{
		memset(curProfit,0,sizeof(curProfit));
		memset(futureProfit,0,sizeof(futureProfit));
		for(int i=0;i<n;++i) cin>>price[i];
		int low=price[0];
		int maxProfit=0;
		for(int i=1;i<n;++i)
		{
			low=min(low,price[i]);
			curProfit[i]=max(curProfit[i-1],price[i]-low);
		} 
		int high=price[n-1];
		for(int i=n-1;i>=0;--i)
		{
			high=max(high,price[i]);
			if(i<n-1) futureProfit[i]=max(futureProfit[i+1],high-price[i]);
			maxProfit=max(maxProfit,curProfit[i]+futureProfit[i]);
		}
		cout<<maxProfit<<endl;
	}
	return 0;
} 
