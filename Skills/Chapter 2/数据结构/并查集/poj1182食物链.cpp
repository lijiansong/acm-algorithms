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
