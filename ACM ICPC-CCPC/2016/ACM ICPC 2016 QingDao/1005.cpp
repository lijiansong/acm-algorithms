#include<cstdio>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a;
		scanf("%d",&a);
		if(a==2) printf("Bad\n");
		else
		{
			if(((a*(a-1)/2)%a)==0) printf("Balanced\n");
			else printf("Bad\n");
		}
	}
	
	return 0;
} 
