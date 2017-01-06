#include<cstdio>
void print_subset(int n,int* a,int cur)
{
	for(int i=0;i<cur;++i) printf("%d ",a[i]);
	printf("\n");
	int s=cur?a[cur-1]+1:0;
	for(int i=s;i<n;++i)
	{
		a[cur]=i;
		print_subset(n,a,cur+1);
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int *a=new int[n];
		for(int i=1;i<=n;++i) a[i-1]=i;
		print_subset(n,a,0);
		delete a;
	}
	return 0;
} 
