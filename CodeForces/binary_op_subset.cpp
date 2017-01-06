/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/01/17 01:34
	Description: 
	A=10110 {1,2,4}
	B=01100 {2,3}
	A&B=00100 {2} 集合的交操作 
	A|B=11110 {1,2,3,4} 集合的并操作 
	A^B=11010 {1,3,4} 集合的对称差操作
	全集ALL_BITS=(1<<n)-1 
*/

#include<cstdio>

//print subset named s of set {0,1,2,...,n-1}
void print_subset(int n,int s)
{
	/*for(int i=0;i<cur;++i) printf("%d ",a[i]);
	printf("\n");
	int s=cur?a[cur-1]+1:0;
	for(int i=s;i<n;++i)
	{
		a[cur]=i;
		print_subset(n,a,cur+1);
	}*/
	/*if(cur==n)
	{
		for(int i=0;i<cur;++i)
		{
			if(a[i]) printf("%d ",i);
		}
		printf("\n");
		return;
	}
	a[cur]=1;
	print_subset(n,a,cur+1);
	a[cur]=0;
	print_subset(n,a,cur+1);*/
	for(int i=0;i<n;++i)
	{
		if(s&(1<<i)) printf("%d ",i);
	}
	printf("\n");
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//int *a=new int[n];
		//for(int i=1;i<=n;++i) a[i-1]=i;
		//print_subset(n,a,0);
		//delete a;
		//enum each subset which is encoded by 0,1,2,...,2^n-1
		for(int i=0;i<(1<<n);++i) print_subset(n,i);
	}
	return 0;
} 
