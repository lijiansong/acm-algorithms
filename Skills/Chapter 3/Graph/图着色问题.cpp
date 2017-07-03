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
