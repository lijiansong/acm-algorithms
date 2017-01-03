#include<cstdio>
#include<cstdlib>
#include<cstring>
const int maxd=20;
int s[1<<maxd];//2^maxd -1
int main()
{
	int d,i;
	while(scanf("%d%d",&d,&i)==2)
	{
		memset(s,0,sizeof(s));
		int k,n=(1<<d)-1;
		for(int j=0;j<i;++j)
		{
			k=1;
			for(;;)
			{
				s[k]=!s[k];
				k=s[k]?k*2:k*2+1;
				if(k>n) break;
			}
		}
		printf("%d\n",k/2);
	}
	return 0;
} 
