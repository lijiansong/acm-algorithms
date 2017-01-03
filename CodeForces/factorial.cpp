#include<cstdio>
#include<cstring>
const int maxn=3000;
int fact[maxn];
int main()
{
	int i,j,n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(fact,0,sizeof(fact));
		fact[0]=1;
		for(i=2;i<=n;++i)
		{
			int c=0;
			for(j=0;j<maxn;++j)
			{
				int s=fact[j]*i+c;
				fact[j]=s%10;
				c=s/10;
			}
		}
		for(j=maxn-1;j>=0;--j)
		{
			if(fact[j]) break;
		}
		for(i=j;i>=0;--i)
		{
			printf("%d",fact[i]);
		}
		printf("\n");
	}
	return 0;
} 
