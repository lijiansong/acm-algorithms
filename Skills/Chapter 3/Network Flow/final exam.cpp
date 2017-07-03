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
