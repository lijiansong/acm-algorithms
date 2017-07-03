/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/16 15:07
	Description: 
	poj 2386
	lake counting
	从任意的W地方开始，不停地把邻接的部分替换成'.'
	1此dfs后与初始的这个W连接的所有的W就都被替换成了'.'，直到图中不在存在W为止
	总共进行dfs的次数就是答案
	 
	时间复杂度为O(8*N*M)=O(N*M) 
*/
#include<iostream>
using namespace std;
const int MAX_N=100;
const int MAX_M=100;
int N,M;
char field[MAX_N][MAX_M+1];
//现在所处的位置为x，y 
void dfs(int x,int y)
{
	field[x][y]='.';
	for(int dx=-1;dx<=1;dx++)
	{
		for(int dy=-1;dy<=1;dy++)
		{
			int nx=x+dx;
			int ny=y+dy;
			if(0<=nx&&nx<N&&0<=ny&&ny<M&&field[nx][ny]=='W')
				dfs(nx,ny);
		}
	}
	return;
}
void solve()
{
	int res=0;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			if(field[i][j]=='W')
			{
				dfs(i,j);
				res++;
			}
		}
	}
	cout<<res<<endl;
}
int main()
{
	while(cin>>N>>M)
	{
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<M;++j)
			{
				cin>>field[i][j];
			}
		}
		solve();
	}
	return 0;
}
 
