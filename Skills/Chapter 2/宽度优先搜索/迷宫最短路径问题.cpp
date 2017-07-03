/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/16 16:52
	Description: 迷宫最短路径问题
	宽度优先遍历 
*/
#include<iostream>
#include<queue>
using namespace std;
const int INF=100000000;
const int MAX_N=100;
const int MAX_M=100;
//利用pair表示状态 
typedef pair<int,int> P;

//输入
char maze[MAX_N][MAX_M+1];//表示迷宫的字符串数组
int N,M;
int sx,sy;//起点坐标
int gx,gy;//终点坐标
int d[MAX_N][MAX_M];//到各个位置的最短距离数组
//四个方向移动的向量
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
//求从(sx,sy)到(gx,gy)的最短距离
//如果无法到达则是INF
int bfs()
{
	queue<P> que;
	//把所有的位置都初始化为INF
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			d[i][j]=INF;
	//将起点加入队列，并把这一地点的距离设置为0
	que.push(P(sx,sy));
	d[sx][sy]=0;
	
	//不断循环直到队列的长度为0
	while(que.size())
	{
		//把队列的最前端元素取出 
		P p=que.front();que.pop();
		//如果取出的状态已经是终点，则结束搜索
		if(p.first==gx&&p.second==gy)break;
		//4个方向循环
		for(int i=0;i<4;++i)
		{
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			//判断是否可以移动以及是否已经访问过（d[nx][ny]!=INF即为已经访问过）
			if(0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF)
			{
				//可以移动的话则加入到队列，并且该位置的距离确定为到p的距离加1
				que.push(P(nx,ny));
				d[nx][ny]=d[p.first][p.second]+1; 
			}
		}
	}
	return d[gx][gy];
} 
void solve()
{
	int res=bfs();
	cout<<res<<endl;
}
int main()
{
	while(cin>>N>>M)
	{
		for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			cin>>maze[i][j];
		}
		
		for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			if(maze[i][j]=='S')
			{
				sx=i;sy=j;
			}
			if(maze[i][j]=='G')
			{
				gx=i;gy=j;
			}
		}
		solve();
	}
	return 0;
}
