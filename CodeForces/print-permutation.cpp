#include<cstdio>
#include<cstring>
const int maxn=1000;
void print_permutation(int n,int* a,int cur)
{
	int i,j;
	//boundary
	if(cur==n)
	{
		for(i=0;i<n;++i) printf("%d ",a[i]);
		printf("\n");
	}
	//尝试在a[cur]填各种整数i
	else
	{
		for(i=1;i<=n;++i)
		{
			int ok=1;
			for(j=0;j<cur;++j)
			{
				if(a[j]==i) ok=0;
			}
			if(ok)
			{
				a[cur]=i;
				print_permutation(n,a,cur+1);
			}
		}
	}
}
int main()
{
	int n,a[maxn];
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;++i)
		{
			//scanf("%d",&a[i]);
			a[i]=i+1;
		}
		print_permutation(n,a,0);
	}
	return 0;
} 
