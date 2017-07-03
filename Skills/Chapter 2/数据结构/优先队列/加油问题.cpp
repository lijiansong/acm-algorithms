/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/09/16 16:38
	Description: poj2431 
*/
#include<iostream>
#include<queue>
using namespace std;
const int MAX_N=10000;
int L,P,N;//L:distance; P:initial oil; N: nums of oil station
int A[MAX_N+1],B[MAX_N+1];//A: distance of oil station; B: max oil of every station
void solve()
{
	A[N]=L,B[N]=0,N++;
	int ans=0,pos=0,d=0,tank=P;
	priority_queue<int> que;
	
	for(int i=0;i<N;++i)
	{
		d=A[i]-pos;
		while(tank-d<0)
		{
			if(que.empty())
			{
				puts("-1");
				return;
			}
			tank+=que.top();
			que.pop();
			ans++;
		}
		tank-=d;
		pos=A[i];
		que.push(B[i]);
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>N>>L>>P)
	{
		for(int i=0;i<N;++i)
			cin>>A[i];
		for(int i=0;i<N;++i)
			cin>>B[i];
		 solve();
	}
	return 0;
}

