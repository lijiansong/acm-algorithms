ACM Algorithms
============================
> This archive is about the acm algorithm, which exists frequently in ACM Competitions. It also can be treated as summary of these algorithms. Some examples refer to the book 《Challenge Competition of Programing Design》.

## Content

* [Chapter 2](#chapter-2)
  * [深度优先搜索](#深度优先搜索)
    * [部分和问题](#部分和问题)
    * [poj2386 lake counting](#poj2386-lake-counting)
  * [宽度优先搜索](#宽度优先搜索)
    * [迷宫最短路径问题](#迷宫最短路径问题)
  * [贪心法](#贪心法)
    * [硬币问题](#硬币问题)

## Summary

### Chapter 2

#### 深度优先搜索

##### 部分和问题

```
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
```

##### poj2386 lake counting
> 从任意的W地方开始，不停地把邻接的部分替换成'.'，1次dfs后与初始的这个W连接的所有的W就都被替换成了'.'，直到图中不在存在W为止，总共进行dfs的次数就是答案，时间复杂度为O(8*N*M)=O(N*M) 

```
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
```

#### 宽度优先搜索
> 深度优先搜索隐式地用栈进行计算，而宽度优先搜索则利用了队列.
> 搜索时首先将初始状态添加到队列里，此后从队列的最前端不断取出状态，把从该状态可以转移到的状态中尚未访问过的部分加入队列，如此往复，直到队列被取空或者找到了问题的解.
> 宽度优先搜索按照距开始状态由近及远的顺序进行搜索，因此可以很容易地用来求解最短路径、最少操作之类的问题.
> 在宽度优先搜索中，只要将已经访问过的状态用标记管理起来，就可以很好地做到由远及近搜索.
> 宽度优先搜索会把状态逐个加入队列，因此通常需要与状态数成正比的内存空间. 反之，深度优先搜索是与最大递归深度成正比的. 一般与状态数成正比，递归的深度并不会太大，所以可以认为深度优先搜索可以更加节省内存.

##### 迷宫最短路径问题
> 在迷宫最短路径问题中，状态仅仅是目前所在的位置的坐标，因此可以构造成pair或者编码成int来表达状态，当状态更加复杂时，就需要封装成一个类来表示状态了.

```
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

```
#### 贪心法
> 贪心法就是遵循某种规则，不断贪心地选取当前最优策略的算法设计方法.

##### 硬币问题
```
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
```


##Postscript

> This archive will be updated regularly.
