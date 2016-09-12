ACM Algorithms
============================
> This archive is about the acm algorithm, which exists frequently in ACM Competitions. It also can be treated as summary of these algorithms. Some examples refer to the book 《Challenge Competition of Programing》.

## Content

* [Chapter 2](#chapter-2)
  * [深度优先搜索](#深度优先搜索)
    * [部分和问题](#部分和问题)
    * [poj2386 lake counting](#poj2386-lake-counting)
  * [宽度优先搜索](#宽度优先搜索)
    * [迷宫最短路径问题](#迷宫最短路径问题)
  * [贪心法](#贪心法)
    * [硬币问题](#硬币问题)
    * [区间调度问题](#区间调度问题)
    * [poj3617 字典序最小问题](#poj3617-字典序最小问题)
    * [poj3069 Saruman's Army](#poj3069-sarumans-army)
    * [poj3253 Fence Repair](#poj3253-fence-repair)
  * [记忆化搜索与动态规划](#记忆化搜索与动态规划)
    * [01背包问题](#01背包问题)
      * [朴素解法](#朴素解法)
      * [DP解法](#dp解法)
    * [最长公共子序列问题](#最长公共子序列问题)
  * [数据结构](#数据结构)
    * [优先队列](#优先队列)
      * [poj2431 Expedition](#poj2431-expedition)
    * [二叉搜索树](#二叉搜索树)
    * [并查集](#并查集)
      * [poj1182食物链](#poj1182食物链)
    * [线段树](#线段树)
* [Chapter 3](#chapter-3)
  * [图论](#图论)
  * [数学问题](#数学问题)
  * [网络流](#网络流)
  * [计算几何](#计算几何)
  

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
[↑ top](#acm-algorithms)
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
[↑ top](#acm-algorithms)
#### 宽度优先搜索
> 深度优先搜索隐式地用栈进行计算，而宽度优先搜索则利用了队列.<br>
> 搜索时首先将初始状态添加到队列里，此后从队列的最前端不断取出状态，把从该状态可以转移到的状态中尚未访问过的部分加入队列，如此往复，直到队列被取空或者找到了问题的解.<br>
> 宽度优先搜索按照距开始状态由近及远的顺序进行搜索，因此可以很容易地用来求解最短路径、最少操作之类的问题.<br>
> 在宽度优先搜索中，只要将已经访问过的状态用标记管理起来，就可以很好地做到由远及近搜索.<br>
> 宽度优先搜索会把状态逐个加入队列，因此通常需要与状态数成正比的内存空间. 反之，深度优先搜索是与最大递归深度成正比的.<br> 一般与状态数成正比，递归的深度并不会太大，所以可以认为深度优先搜索可以更加节省内存.<br>

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
[↑ top](#acm-algorithms)
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
[↑ top](#acm-algorithms)
##### 区间调度问题
> 贪心算法，在可选的任务中，每次都选取结束时间最早的任务.

```
/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/08/16 08:37
	Description: 
	区间调度问题
	贪心算法 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N=10000;
int n,s[MAX_N],t[MAX_N];
pair<int,int> itv[MAX_N];
void solve()
{
	//对pair进行的是字典序比较
	//为了让结束时间早的任务排在前面，把t存入first，把s存入second 
	for(int i=0;i<n;++i)
	{
		itv[i].first=t[i];
		itv[i].second=s[i];
	}
	sort(itv,itv+n);
	int ans=0,t=0;
	for(int i=0;i<n;++i)
	{
		if(t<itv[i].second)
		{
			ans++;
			t=itv[i].first;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
			cin>>s[i];
		for(int i=0;i<n;++i)
			cin>>t[i];
		solve();
	}
	return 0;
} 
```
[↑ top](#acm-algorithms)
##### poj3617 字典序最小问题
> 不断取S的开头和末尾中较小的一个字符放到T的末尾，对于S的末尾和开头字符相同的情形，为了尽早地使用下一个字符，需要比较下一个字符的大小，而下一个字符也有可能相同，所以有如下算法：
> - 按照字典序比较S和将S反转后的字符串S’；
> - 如果S较小，就从S的开头取出一个字符，追加到T的末尾；
> - 如果S’较小，就从S的末尾取出一个字符，追加到T的末尾(如果相同，取哪一个都可以).

```
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX_N=2000;
char s[MAX_N];
int n;
void solve()
{
	int a=0,b=n-1;
	while(a<=b)
	{
		bool left=false;
		for(int i=0;a+i<b;++i)
		{
			if(s[a+i]<s[b-i])
			{
				left=true;
				break;
			}
			else if(s[a+i]>s[b-i])
			{
				left=false;
				break;
			}
		}
		if(left)
			putchar(s[a++]);
		else
			putchar(s[b--]);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>n&&n)
	{
		for(int i=0;i<n;++i)
			cin>>s[i];
		solve();
	}
	fclose(stdin);
	return 0;
} 
```
[↑ top](#acm-algorithms)
##### poj3069 Saruman's Army

```
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N=1001;
int x[MAX_N],r,n;
void solve()
{
	sort(x,x+n);
	int ans=0;
	int left=0,index=0;
	//bool marked=false;
	while(index<n)
	{
		while(x[left]<=(x[index]+r))
			left++;
		
		ans++;
		index=left-1;
		//left++;
		
		while(x[left]<=(x[index]+r))
			left++;
		index=left;
		left++;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>n&&n)
	{
		cin>>r;
		for(int i=0;i<n;++i)
			cin>>x[i];
		solve();
	}
	fclose(stdin);
	return 0;
} 

```
[↑ top](#acm-algorithms)
##### poj3253 Fence Repair
> 切割方法看成是二叉树，叶子节点的深度就对应了为了得到对应模板所需的切割次数，开销的合计就是各个叶子节点的<br>
> **木板的长度 x 节点的深度**<br>
> 的总和。最近切割方法应具有如下的性质：<br>
> **最短的板与次短的板的节点应当是兄弟节点**。
> 实际上，求解过程就是在**构造一棵哈夫曼树**。

```
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int MAX_N = 20000;
int n, len[MAX_N] = { 0 };
void solve()
{
	int ans = 0;
	while (n>1)
	{
		int min1 = 0, min2 = 1;
		if (len[min1] > len[min2])
			swap(min1, min2);
		for (int i = 2; i < n;++i)
		{
			if (len[i] < len[min1])
			{
				min1 = i;
				min2 = min1;
			}
			else if (len[i] < len[min2])
				min2 = i;
		}
		int t = len[min1] + len[min2];
		ans += t;
		if (min1 == n - 1)
			swap(min1, min2);

		len[min1] = t;
		len[min2] = len[n - 1];
		n--;
	}
	cout << ans << endl;
}
int main()
{
	freopen("in.txt", "r", stdin);
	while (cin>>n&&n)
	{
		for (int i = 0; i < n; ++i)
			cin >> len[i];
		solve();
	}
	fclose(stdin);
	return 0;
}
```
[↑ top](#acm-algorithms)
#### 记忆化搜索与动态规划
> **动态规划（DP：Dynamic Programming）**

##### 01背包问题
> n个重量和价值分别为wi和vi。从这些物体中挑选总重量不超过w的物体，求所有挑选方案中价值总和的最大值。

###### 朴素解法
> 针对每个物体是否放入背包，进行搜索

```
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;
int weight[MAX_N]={0},value[MAX_N]={0},n,max_w;
//从第i个物品开始挑选总重小于w的部分 
int rec(int i,int w)
{
	int ans;
	//没有剩余的物品了 
	if(i==n)
		ans=0;
	//无法挑选这个物品 
	else if(w<weight[i]) 
		ans=rec(i+1,w);
	//挑选和不挑选都尝试一下 
	else
		ans=max(rec(i+1,w-weight[i])+value[i],rec(i+1,w));
	return ans;
}
void solve()
{
	cout<<rec(0,max_w)<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while (cin>>n&&n)
	{
		for(int i=0;i<n;++i)
			cin>>weight[i]>>value[i];
		cin>>max_w;
		solve();
	}
	fclose(stdin);
	return 0;
}

```
> 该方法的搜索深度是n，而且每一层搜索都要进行两次分支，最坏需要O(2^n)的时间。针对每个物体是否放入背包向下搜索尝试。

[↑ top](#acm-algorithms)
###### DP解法
> 对于递归函数rec(i,j)，只要参数相同，返回的结果就相同，所以把第一次计算时的结果记录下来，省掉第二次以后的重复计算。参数的组合不过有n * w种，所以时间复杂度为O(n * w)。这种方法称为 **记忆化搜索**。

```
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N=101;
const int MAX_W=10001;
int dp[MAX_N][MAX_W];
int weight[MAX_N]={0},value[MAX_N]={0},n,max_w;
//从第i个物品开始挑选总重小于w的部分 
int rec(int i,int w)
{
	if(dp[i][w]>=0)
		return dp[i][w];
	int ans;
	//没有剩余的物品了 
	if(i==n)
		ans=0;
	//无法挑选这个物品 
	else if(w<weight[i]) 
		ans=rec(i+1,w);
	//挑选和不挑选都尝试一下 
	else
		ans=max(rec(i+1,w-weight[i])+value[i],rec(i+1,w));
	dp[i][w]=ans;
	return dp[i][w];
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,max_w)<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while (cin>>n&&n)
	{
		for(int i=0;i<n;++i)
			cin>>weight[i]>>value[i];
		cin>>max_w;
		solve();
	}
	fclose(stdin);
	return 0;
}

```

> dp[i][j]表示从第i个物品开始挑选总重量小于j时，总价值的最大值。有如下的地推公式<br>
> dp[n][j]=0<br>
> dp[i][j]=dp[i+1][j],if j<w[i],其他情况，dp[i][j]=max(dp[i+1][j-w[i]]+v[i],dp[i+1][j])<br>
> 不用写递归函数，直接利用递推式将各项的值计算出来，利用二重循环也可以解决这一问题。

```
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N=101;
const int MAX_W=10001;
int dp[MAX_N][MAX_W];
int weight[MAX_N]={0},value[MAX_N]={0},n,max_w;
void solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=n-1;i>=0;--i)
	{
		for(int j=0;j<=max_w;++j)
		{
			if(j<weight[i])
				dp[i][j]=dp[i+1][j];
			else
				dp[i][j]=max(dp[i+1][j],dp[i+1][j-weight[i]]+value[i]);
		}
	}
	cout<<dp[0][max_w]<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while (cin>>n&&n)
	{
		for(int i=0;i<n;++i)
			cin>>weight[i]>>value[i];
		cin>>max_w;
		solve();
	}
	fclose(stdin);
	return 0;
}

```
[↑ top](#acm-algorithms)

##### 最长公共子序列问题
> Description: 给定两个字符串，求出这两个字符串最长的公共子序列的长度。e.g. m=4,n=4,s="abcd",t="bfcd",返回3. ("bcd"). 定义dp[i][j]表示s1s2...si和t1t2...tj的最长公共子序列的长度，则 很容易得出，s1s2...si+1和t1t2...tj+1的公共子序列可能是<br>当si+1=ti+1时，在dp[i][j]的末尾追加si+1;<br>s1s2...si和t1t2...tj+1的公共子列;<br>s1s2...si+1和t1t2...tj的公共子列.

```
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAX_N=1000;
const int MAX_M=1000;
char s[MAX_N],t[MAX_M];
int n,m,dp[MAX_N][MAX_M];
void solve()
{
	dp[0][0]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(s[i+1]=t[i+1])
			{
				dp[i+1][j+1]=dp[i][j]+1;
			}
			else
			{
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
	cout<<dp[n][m]<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>n>>m)
	{
		for(int i=0;i<n;++i)
			cin>>s[i];
		for(int j=0;j<m;++j)
			cin>>t[j];
		solve();
	}
	return 0;
} 
```
[↑ top](#acm-algorithms)

#### 数据结构
> 常用的数据结构：堆、二叉搜索书、并查集、线段树等

##### 优先队列
> 优先队列能完成下列操作：插入一个数值；取出最小(最大)的数值，利用“小根堆”能够高效地解决最小数值的问题；C++中，STL的proority_queue取出数值得到的是最大值。

###### poj2431 Expedition
> 当经过加油站i时，向优先队列中插入B[i];<br>当燃料箱为空时，
- 如果优先队列也是空的，则无法到达终点；
- 否则取出优先队列中的最大元素，并给卡车加油。

```
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
```
[↑ top](#acm-algorithms)

##### 二叉搜索树

##### 并查集
> 并查集是使用树形结构实现的，不是二叉树。并查集的初始化，n个节点最开始的时候没有边；合并操作，从一个组的跟向另外一个组的跟连边，两棵树变成了一棵树，把两个组合并成了一个组；查询，查询两个节点是否属于同一个组，沿着树向上走，来查询包含这个元素的根是谁，如果两个节点走到了同一个跟，那么就属于同一个组。并查集实现的时候，需要避免退化，对于每棵树记录这个树的高度rank；同时记得路径压缩，对于每个节点，一旦向上走到了一次根节点，就把这个点到父节点的边改成直接连向根的边。在使用这种简化的方法时，为了简单起见，即使树的高度发生了变化，也不改变rank的值。

###### poj1182食物链

```
#include<cstdio>
using namespace std;
const int MAX_K=100000;
const int MAX_N=50000;
int par[MAX_N];
int rank[MAX_N];
int n,k,T[MAX_K],X[MAX_K],Y[MAX_K];
//初始化n个元素
void init(int n)
{
	for(int i=0;i<n;++i)
	{
		par[i]=i;
		rank[i]=0;
	}
} 
//查询树的根
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
} 
//合并x和y所属的集合
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rank[x]<rank[y])
	{
		par[x]=y;
	}
	else
	{
		par[y]=x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
}
//判断x和y是否属于同一个集合
bool same(int x,int y)
{
	return find(x)==find(y);
} 

void solve()
{
	init(n*3);
	int ans=0;
	for(int i=0;i<k;++i)
	{
		int t=T[i];
		int x=X[i]-1,y=Y[i]-1;
		if(x<0||n<=x||y<0||n<=y)
		{
			ans++;
			continue;
		}
		if(t==1)
		{
			if(same(x,y+n)||same(x,y+2*n))
			{
				ans++;
			}
			else
			{
				unite(x,y);
				unite(x+n,y+n);
				unite(x+2*n,y+2*n);
			}
		}
		else
		{
			if(same(x,y)||same(x,y+2*n))
			{
				ans++;
			}
			else
			{
				unite(x,y+n);
				unite(x+n,y+2*n);
				unite(x+2*n,y);
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		for(int i=0;i<k;++i)
		{
			scanf("%d %d %d",&T[i],&X[i],&Y[i]);
		}
		solve();
	}
	return 0;
} 
```

##### 线段树

### Chapter 3

#### 图论

#### 数学问题

#### 网络流

#### 计算几何



## License
> [The MIT License (MIT)](http://opensource.org/licenses/MIT)

> **Copyright (c) 2016 Json Lee**

> Permission is hereby granted, free of charge, to any person obtaining a copy  
> of this software and associated documentation files (the "Software"), to deal  
> in the Software without restriction, including without limitation the rights  
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  
> copies of the Software, and to permit persons to whom the Software is  
> furnished to do so, subject to the following conditions:  
> 
> The above copyright notice and this permission notice shall be included in  
> all copies or substantial portions of the Software.  

> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  
> THE SOFTWARE.  

##Postscript

> This archive will be updated regularly.

[↑ top](#acm-algorithms)
