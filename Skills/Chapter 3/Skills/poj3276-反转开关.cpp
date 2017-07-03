#include<cstdio>
#include<cstring>
const int maxn=0x7ffff;
int N,dir[maxn];//dir:direction 0:F,1:B
int f[maxn];//区间[i,i+K-1]是否进行反转 
//固定k,求最小的操作次数 
int calc(int K)
{
	memset(f,0,sizeof(f));
	int res=0,sum=0;
	for(int i=0;i+K<=N;++i)
	{
		//计算区间[i,i+K-1]
		if((dir[i]+sum)%2!=0)
		{
			++res;
			f[i]=1;
		} 
		sum+=f[i];
		if(i-K+1>=0) sum-=f[i-K+1];
	}
	//检查剩下的牛是否有面朝后方的情况
	for(int i=N-K+1;i<N;++i)
	{
		if((dir[i]+sum)%2!=0) return -1;
		if(i-K+1>=0) sum-=f[i-K+1];
	} 
	return res;
}
void solve()
{
	int K=1,M=N;
	for(int k=1;k<=N;++k)
	{
		int m=calc(k);
		if(m>=0&&M>m)
		{
			M=m;
			K=k;
		}
	}
	printf("%d %d\n",K,M);
}
int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=0;i<N;++i) scanf("%d",&dir[i]);
		solve();
	} 
	return 0;
} 
