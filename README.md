ACM Algorithms
============================
> This archive is about the acm algorithm, which exists frequently in ACM Competitions. It also can be treated as summary of these algorithms. Some examples refer to the book 《Challenge Competition of Programing》.

> 无意中发现了[HelloGCC](http://www.hellogcc.org/), 其实线下的时候开发几个[开源工具](https://github.com/hellogcc)也是不错的...

> 找时间自己写一个`完整的 健壮的`编译器还是很有必要的，Todo: based on LLVM & Clang, or just in Cpp/C

[ACM Software System Award full lists...](http://awards.acm.org/software_system/year.cfm?spm=5176.100239.blogcont59983.5.8KVraM&file=year.cfm)

[reStructuredText标记语言](http://sphinx-doc-zh.readthedocs.io/en/latest/rest.html)相对Markdown来说，使用Sphinx能够自动生成目录和索引文件，方便查询和检索...


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
    * [二分图](#图的着色问题)
    * [poj3169 Layout](#poj3169-layout)
  * [数学问题](#数学问题)
  * [网络流](#网络流)
    * [最小割](#zoj2587最小割的唯一性判定)
    * [final examination](#final-examination)
  * [Skills](#skills)
    * [poj3061尺取法](#poj3061尺取) 
    * [poj3320尺取法](#poj3320尺取法)
    * [poj3276开关问题](#poj3276开关问题)
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
> 快排分区函数： 随机选择一个数作为枢纽元（pivot），这里选择第一个数，把比枢纽元小的数放在数组的左边，把大于等于枢纽元的数移到数组的右边，一趟遍历过后枢纽元归位， 返回枢纽元的位置下标 .

```
int partition(int a[],int start,int end)
{
	int pivotIndex=start;
	int pivot=a[pivotIndex];
	swap(a[pivotIndex],a[end]);
	int storeIndex=start;
	for(int i=0;i<end;++i)
	{
		if(a[i]<pivot)
		{
			swap(a[i],a[storeIndex]);
			++storeIndex;
		}
	}
	swap(a[storeIndex],a[end]);
	return storeIndex;
}
int partition_(int a[],int start,int end)
{
	int pivotIndex=start;
	int pivot=a[pivotIndex];
	swap(a[pivotIndex],a[end]);
	int storeIndex=start;
	for(int i=0;i<end;++i)
	{
		if(a[i]<pivot)
		{
			if(i!=storeIndex)
			{
				swap(a[i],a[storeIndex]);
			}
			++storeIndex;
		}
	}
	swap(a[storeIndex],a[end]);
	return storeIndex;
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
##### 图的着色问题

```
#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int MAX_V=1000;

vector<int> G[MAX_V];//图的邻接表 
int V;int color[MAX_V];//顶点的颜色为1或者-1 
bool dfs(int v,int c)
{
	color[v]=c;//把顶点v染成颜色c 
	for(int i=0;i<G[v].size();++i)
	{
		//相邻顶点同色 
		if(color[G[v][i]]==c) return false;
		//如果相邻顶点还没被染色，则染成-c 
		if(color[G[v][i]]==0&&!dfs(G[v][i],-c)) return false;
	}
	//如果所有顶点都染过了
	return true; 
}
void solve()
{
	for(int i=0;i<V;++i)
	{
		//如果顶点i还没被染色，则染成1 
		if(color[i]==0)
		{
			if(!dfs(i,1))
			{
				printf("No\n");
				return;
			}
		}
	}
	printf("Yes\n");
} 
int main()
{
	//V=3;
	//G[MAX_V]={{1,2},{0,2},{0,1}};
	solve();
	return 0;
}
```
[↑ top](#acm-algorithms)

##### poj3169 Layout
> 查分约束

```
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_ML = 10001;
const int MAX_MD = 10001;
const int MAX_N = 1001;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];
const int INF = 1000001;
int d[MAX_N];//第i号牛的位置
int N, ML, MD;
void solve()
{
	fill(d, d + N, INF);
	d[0] = 0;
	for (int k = 0; k < N; ++k)
	{
		//i+1 to i weight is 0
		for (int i = 0; i + 1 < N; ++i)
		{
			if (d[i + 1] < INF)
				d[i] = min(d[i], d[i + 1]);
		}
		//AL to BL weight is DL
		for (int i = 0; i < ML; ++i)
		{
			if (d[AL[i] - 1] < INF)
				d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
		}
		//BD to AD weight is -DD
		for (int i = 0; i < MD; ++i)
		{
			if (d[BD[i] - 1] < INF)
				d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
		}
	}
	int res = d[N - 1];
	if (d[0] < 0)
	{
		res = -1;
	}
	else if (res == INF)
	{
		res = -2;
	}
	printf("%d\n", res);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d %d %d", &N, &ML, &MD) != EOF)
	{
		for (int i = 0; i < ML; ++i)
			scanf("%d %d %d", &AL[i], &BL[i], &DL[i]);
		for (int i = 0; i < MD; ++i)
			scanf("%d %d %d", &AD[i], &BD[i], &DD[i]);
		solve();
	}
	return 0;
}
```
[↑ top](#acm-algorithms)

#### 数学问题

#### 网络流
##### woj1008
```
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm> 
using namespace std;
#define N 210 
int m,n,k,a[N],flow[N][N],capacity[N][N],s,t,f,p[N];
void MaxFlow()
{
    queue<int> q;
    memset(flow,0,sizeof(flow));
    f=0;
    for(;;)
    {
        memset(a,0,sizeof(a));
        a[s]=0xfffffff;
        q.push(s);
        while(!q.empty())//BFS寻找增广路径 
        {
            int u=q.front();
            q.pop();
            for(int v=1;v<=t;++v)
            {
                //找到新节点v 
                if(!a[v] && capacity[u][v] > flow[u][v])
                {
                    p[v]=u;q.push(v);//记录v的父节点，并加入队列 
                    a[v]=min(a[u],capacity[u][v]-flow[u][v]);
                }
            }
        }
        if(a[t]==0)break;//找不到则当前流即为最大流 
        for(int u=t;u!=s;u=p[u])//从汇点往回走 
        {
            flow[p[u]][u]+=a[t];//更新正向流量 
            flow[u][p[u]]-=a[t];//更新反向流量 
        }
        f+=a[t];//更新从s流出的总流量
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    while(cin>>m>>n)
    {
        memset(capacity,0,sizeof(capacity));
        s=0;
        t=m+n+1;
        f=0;
        int ani=m+1,temp;
        for(i=1;i<=m;++i)
        {
            for(j=0;j<n;++j)
            {
                cin>>temp;
                if(temp==1)
                    capacity[i][ani+j]=1;
                capacity[ani+j][t]=1;
            }
        }
        cin>>k;
        for(i=1;i<=m;++i)
        {
            capacity[0][i]=k;
        }
        MaxFlow();
        if(f==n)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    return 0;
}
```

##### zoj2587最小割的唯一性判定
```
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int SS = 805, TT = 806;
const int INF = 0x3fffffff;
int N, M, A, B;

struct Edge {
    int v, c, next;    
};
Edge e[30000];
int idx, head[810], lv[810];
int front, tail, que[810];
int vis[810];

void insert(int a, int b, int c) {
    e[idx].v = b, e[idx].c = c;
    e[idx].next = head[a];
    head[a] = idx++;
}

bool bfs() {
    memset(lv, 0xff, sizeof (lv));
    front = tail = lv[SS] = 0;
    que[tail++] = SS;
    while (front < tail) {
        int u = que[front++];
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (!(~lv[v]) && e[i].c) {
                lv[v] = lv[u] + 1;
                if (v == TT) return true;
                que[tail++] = v;    
            }
        }
    }
    return false;
}

int dfs(int u, int sup) {
    if (u == TT) return sup;
    int tf = 0, f;
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (lv[u]+1==lv[v] && e[i].c && (f=dfs(v, min(e[i].c, sup-tf)))) {
            tf += f;
            e[i].c -= f, e[i^1].c += f;
            if (tf == sup) return sup;    
        }
    }
    if (!tf) lv[u] = -1;
    return tf;
}

void dinic() {
    int ret = 0;
    while (bfs()) {
        ret += dfs(SS, INF);    
    }
//    printf("ret = %d\n", ret); 
}

void flood(int u, int &cnt) {
    for (int i = head[u]; i != -1; i = e[i].next) {
        if (e[i].c && !vis[e[i].v])    {
            ++cnt;
            vis[e[i].v] = 1;
            flood(e[i].v, cnt);
        }
    }
}

void flood_r(int u, int &cnt) {
    for (int i = head[u]; i != -1; i = e[i].next) {
        if (e[i^1].c && !vis[e[i].v])    {
            ++cnt;
            vis[e[i].v] = 1;
            flood_r(e[i].v, cnt);
        }
    }
}

bool query() {
    int cnta = 0, cntb = 0; // 分别为从两个方向进行搜索而计数
    memset(vis, 0, sizeof (vis));
    vis[SS] = vis[TT] = 1;
    flood(SS, cnta);
    memset(vis, 0, sizeof (vis));
    vis[SS] = vis[TT] = 1;
    flood_r(TT, cntb);
    return cnta + cntb == N;
}

int main() {
    while (scanf("%d %d %d %d", &N, &M, &A, &B), N|M|A|B) {
        int a, b, c;
        idx = 0;
        memset(head, 0xff, sizeof (head));
        insert(SS, A, INF), insert(A, SS, 0);
        insert(B, TT, INF), insert(TT, B, 0);
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            insert(a, b, c), insert(b, a, c);
        }
        dinic();
        printf(query() ? "UNIQUE\n" : "AMBIGUOUS\n");
    }
    return 0;        
}
```

##### Final Examination
题目大意：`m*n`的格子中放了一些物体，用枪打这些东西，一次可以打掉一行或者一列，求最少需要多少发子弹干掉所有的物体。题目难在如何建模，如何表示每次消掉一行，或者一列，当时有点急，直接画了个类似二分匹配的模型，即`m*n的矩阵，m行n列，每行对应一个节点，每列对应一个节点，如果某一行某一列有一个物体，就在某行某列对应的节点之间加一个边，s向所有的行节点引一条边，列节点向t引一条边，所有边的容量限制为1，跑一遍最大流算法，最大流值即需要几发子弹`

```
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxv=100;//max node num
const int maxk=1000;//max object num

int n,m,k;//grid size:n*m, n rows and m cloumns, k objects
int x[maxk],y[maxk];//position of objects

int v;//node num
vector<int> g[maxv];//adjacency table of graph
int match[maxv];
bool visited[maxv];
void add_edge(int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}
//dfs find the augumenting path
bool dfs(int v)
{
	visited[v]=true;
	for(int i=0;i<g[v].size();++i)
	{
		int u=g[v][i],w=match[u];
		if(w<0 || !visited[w] && dfs(w))
		{
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}
int bi_match()
{
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<v;++i)
	{
		if(match[i]<0)
		{
			memset(visited,0,sizeof(visited));
			if(dfs(i)) ++ans;
		}
	}
	return ans;
}

void solve()
{
	v=n+m;
	for(int i=0;i<k;++i)
	{
		add_edge(x[i]-1,n+y[i]-1);
	}
	printf("%d\n",bi_match());
}
int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		scanf("%d",&k);
		for(int i=0;i<k;++i) scanf("%d%d",&x[i],&y[i]);
		solve();
	}
	return 0;
} 
```

#### Skills

##### poj3061尺取法
problem：给定长度为n的序列整数a0,a1,a2...an-1以及整数S。求出总和不小于S的连续子序列的长度的最小值.不存在则输出0.
反复推进区间的开头和末尾，来求取满足条件的最小区间的方法称之为`尺取法`。
```
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=0x7ffffff;
int n,S,a[maxn];
void solve()
{
	int res=n+1;
	int s=0,t=0,sum=0;
	for(;;)
	{
		while(t<n&&sum<S) sum+=a[t++];
		if(sum<S) break;
		res=min(res,t-s);
		sum-=a[s++];
	}
	if(res>n) res=0;
	printf("%d\n",res);
}
int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&S)!=EOF)
	{
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		solve();
	}
	return 0;
} 
```

##### poj3320尺取法
problem：一本书有P页，第i页有一个知识点ai，同一个知识点可能出现多次，通过阅读连续的一些页把所有的知识点都覆盖到，求需要阅读的最小页数。
```
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
const int maxp=0x7ffff;
int P,a[maxp];
void solve()
{
	set<int> all;
	for(int i=0;i<P;++i) all.insert(a[i]);
	int n=all.size();
	
	int s=0,t=0,num=0;
	map<int,int> count;//知识点-出现次数 
	int res=P;
	for(;;)
	{
		while(t<P&&num<n)
		{
			if(count[a[t++]]++ ==0) ++num;
		}
		if(num<n) break;
		res=min(res,t-s);
		if(--count[a[s++]]==0) --num; 
	}
	printf("%d\n",res);
}
int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d",&P)!=EOF)
	{
		for(int i=0;i<P;++i) scanf("%d",&a[i]);
		solve();
	}
	return 0;
} 
```
[↑ top](#acm-algorithms)

##### poj3276开关问题


#### 计算几何

- [2016 ACM/ICPC Beijing](http://hihocoder.com/contest/icpcbeijing2016)


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
