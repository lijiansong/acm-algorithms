/*
	Name: 
	Copyright: 
	Author: 
	Date: 08/08/16 22:33
	Description: 
	硬币问题
	贪心算法 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int V[6]={1,5,10,50,100,500};
int A,C[6];//A表示面值，C[i]表示各个面值的硬币的枚数 
void solve()
{
	int ans=0;
	for(int i=5;i>=0;--i)
	{
		int t=min(A/V[i],C[i]);//使用硬币i的枚数
		A-=t*V[i];
		ans+=t; 
	}
	cout<<ans<<endl;
} 
int main()
{
	for(int i=0;i<6;++i)
		cin>>C[i];
	cin>>A;
	solve();
	return 0;
}
