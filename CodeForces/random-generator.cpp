#include<cstdio>
#include<cstdlib>
#include<ctime>
int n=100,m=10000;
//[0,1]之间的均匀随机数 
double random()
{
	return (double)rand()/RAND_MAX;
}
//[0,m-1]之间的均匀随机数 
int random(int m)
{
	return (int)(random()*(m-1)+0.5);
}

int main()
{
	srand(time(NULL));
	printf("%d %d\n",n,m);
	for(int i=0;i<m;++i)
	{
		if(rand()%2==0) printf("A");
		else printf("B");
		int X,Y;
		for(;;)
		{
			X=random(n)+1;
			Y=random(n)+1;
			if(X!=Y) break;
		}
		printf("%d %d\n",X,Y);
	}
	return 0;
} 
