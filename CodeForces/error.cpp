#include<cstdio>
#include<cstring>
#include<cerrno>
int main()
{
	for(int i=0;i<256;++i)
	{
		printf("error.%2d: %s\n",i,strerror(i));
	}
	return 0;
} 
